#!/bin/sh
# Trigger "Build a firmware on demand" on GitHub Actions and download the hex.
#
# Requires: gh (authenticated), git repo with origin pointing to your fork
#
# Examples:
#   bin/fetch-firmware.sh keyball44 my_keymap
#   bin/fetch-firmware.sh keyball44 my_keymap --branch feature/my-keymap
#   bin/fetch-firmware.sh keyball44 my_keymap --download-only
#   bin/fetch-firmware.sh keyball44 my_keymap --output ~/Downloads

set -eu

workflow="Build a firmware on demand"
branch=""
output=""
download_only=0
keyboard=""
keymap=""

usage() {
  sed -n '2,10p' "$0" | sed 's/^# \?//'
  echo
  echo "Options:"
  echo "  --branch BRANCH       Git ref to build (default: current branch)"
  echo "  --output DIR          Download directory (default: firmware/<keyboard>-<keymap>/)"
  echo "  --download-only       Skip build; fetch latest successful artifact on branch"
  echo "  -h, --help            Show this help"
  exit "${1:-0}"
}

while [ $# -gt 0 ]; do
  case "$1" in
    -h|--help) usage 0 ;;
    --branch) shift; branch=${1:?}; shift ;;
    --output) shift; output=${1:?}; shift ;;
    --download-only) download_only=1; shift ;;
    -*) echo "Unknown option: $1" >&2; usage 1 ;;
    *)
      if [ -z "$keyboard" ]; then
        keyboard=$1
      elif [ -z "$keymap" ]; then
        keymap=$1
      else
        echo "Too many arguments" >&2; usage 1
      fi
      shift
      ;;
  esac
done

[ -n "$keyboard" ] && [ -n "$keymap" ] || usage 1

if ! command -v gh >/dev/null 2>&1; then
  echo "gh CLI is required: https://cli.github.com/" >&2
  exit 1
fi

root=$(git rev-parse --show-toplevel 2>/dev/null) || {
  echo "Run this script inside the keyball git repository." >&2
  exit 1
}
cd "$root"

if [ -z "$branch" ]; then
  branch=$(git branch --show-current)
fi

if [ -z "$output" ]; then
  output="firmware/${keyboard}-${keymap}"
fi
mkdir -p "$output"

artifact="${keyboard}-${keymap}-firmware"

if [ "$download_only" -eq 0 ]; then
  echo "Triggering ${workflow} (${keyboard}:${keymap} on ${branch})..."
  gh workflow run "$workflow" --ref "$branch" -f "keyboard=${keyboard}" -f "keymap=${keymap}"
  sleep 3
fi

echo "Waiting for the latest run on branch ${branch}..."
run_id=$(
  gh run list \
    --workflow="$workflow" \
    --branch="$branch" \
    --limit 1 \
    --json databaseId,status \
    --jq '.[0].databaseId'
)

if [ -z "$run_id" ] || [ "$run_id" = "null" ]; then
  echo "No workflow run found for branch ${branch}." >&2
  exit 1
fi

if [ "$download_only" -eq 0 ]; then
  gh run watch "$run_id" --exit-status
else
  status=$(gh run view "$run_id" --json conclusion --jq '.conclusion')
  if [ "$status" != "success" ]; then
    echo "Latest run ${run_id} did not succeed (conclusion=${status})." >&2
    exit 1
  fi
fi

rm -rf "${output:?}/"*
gh run download "$run_id" -D "$output" -n "$artifact"

hex=$(find "$output" -name '*.hex' | head -n 1)
if [ -z "$hex" ]; then
  echo "Download finished but no .hex file found under ${output}" >&2
  exit 1
fi

echo
echo "Downloaded: ${hex}"
echo "Run:        https://github.com/$(gh repo view --json nameWithOwner -q .nameWithOwner)/actions/runs/${run_id}"
