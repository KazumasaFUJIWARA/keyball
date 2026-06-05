
## 2026-06-04T09:06:32+09:00

Keyball44: Remap → QMK my_keymap 移行

- feature/my-keymap ブランチで my_keymap を追加（default ベース → remap_dump 反映）
- remap_dump/keyball44_keymap_dump.txt の EEPROM 4 レイヤーを LAYOUT（右ボール）に変換
- GitHub Actions ビルド成功（例: run 26920897895）
- bin/fetch-firmware.sh を追加（gh workflow run + download-only 対応）
- ユーザーは hex を手動 DL 済み。次回は bin/fetch-firmware.sh keyball44 my_keymap [--download-only]

未確認: 実機書き込み後のキー一致（dump 内の KC_RALT/0x3191 は右ボール物理位置外）

## 2026-06-05T11:04:44+09:00

Keyball44: Remap → QMK my_keymap 移行（書き込み完了）

- feature/my-keymap: remap_dump を keymap.c に反映（LAYOUT 右ボール、hex 値そのまま）
- 書き込み: Pro Micro Web Updater（右 split-right / 左 split-left、COM3）
- Web Serial の InvalidStateError はタイミング・ポート選択で回避。Remap は手元 hex 不可
- bin/fetch-firmware.sh で hex 取得自動化
- 実機動作確認済み（ユーザー報告）
- 今後: キー変更は keymap.c → Actions ビルド → Updater/Toolbox で再書き込み（Remap Configure は不可）

## 2026-06-05T14:14:41+09:00

Keyball44: Unicode 入力成功（WinCompose + UNICODEMAP）

- QMK 標準 UNICODEMAP + UC_WINC（WinCompose）に統一
- L3 ギリシャ / L4 イタalia / L5 数学、OSL(3/4/5) on L2 親指
- 試行錯誤: Alt+hex→WT分割、Alt+10進→0のみ、カスタム handler 廃止
- Windows: 英語(US) キーボード追加、WinCompose 必須
- 実機で è 等の Unicode 入力成功（ユーザー報告「できた！！」）
- latest.hex: firmware/keyball44-my_keymap/latest.hex
