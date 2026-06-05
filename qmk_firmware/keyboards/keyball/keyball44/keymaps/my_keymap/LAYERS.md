# Keyball44 my_keymap — レイヤー対応表

QMK のレイヤー番号は **0 始まり** です。

## レイヤー一覧

| QMK | 名称 | 開き方 |
|-----|------|--------|
| **L0** | ベース | 通常 |
| **L1** | マウス | F 長押し |
| **L2** | 記号・言語 | D 長押し |
| **L3** | ギリシャ文字 | L2 + 親指3番目 OSL |
| **L4** | イタリア語アクセント | L2 + 親指4番目 OSL |
| **L5** | 数学記号 | L2 + 親指5番目 OSL |
| **L6** | 設定（RGB/CPI） | G/H 長押し |

## イタalia語文字を出す手順

| 順番 | キー |
|------|------|
| 1 | **D** 長押し（L2） |
| 2 | **親指・左から4番目** タップ（OSL(4)） |
| 3 | 母音キー（例: F → è） |

## Unicode（Windows + WinCompose 必須）

Keyball にテンキーがないため、**WinCompose** を使います。

1. [WinCompose](https://github.com/samhocevar/wincompose/releases) をインストール
2. Windows 配列を **英語(米国)**、**IME オフ**
3. ファームウェアは `Right Alt + u + 16進 + Enter` を送る（例: è → `u00e8`）

### 過去の失敗パターン

| 症状 | 原因 |
|------|------|
| `+` / WT ペイン分割 | 旧方式 `Alt+Shift+=` が WT ショートカットと衝突 |
| `0` だけ出る | 旧方式 `Alt+0232` が数字行では効かない |

## 書き込み

`firmware/keyball44-my_keymap/latest.hex`  
https://sekigon-gonnoc.github.io/promicro-web-updater/（左右 flash）
