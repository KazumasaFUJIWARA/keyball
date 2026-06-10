# Keyball44 my_keymap — レイヤー対応表

## レイヤー一覧

| QMK | 名称 | 開き方 |
|-----|------|--------|
| **L0** | ベース | 通常 |
| **L1** | マウス | F 長押し |
| **L2** | 記号・言語 | D 長押し |
| **L3** | ギリシャ | L2 + 親指3番目 OSL |
| **L4** | イタリア語 | L2 + 親指4番目 OSL |
| **L5** | 数学記号 | L2 + 親指5番目 OSL |
| **L6** | 設定 | G/H 長押し |

## Unicode（QMK 標準 + WinCompose）

- `rules.mk`: `UNICODEMAP_ENABLE`
- `config.h`: `UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE`（= UC_WINC）
- 記号定義: `keymap.c` 内の `unicode_map[]`
- キーマップ: `X(U_*)` マクロ（例: `X(U_INT)` → ∫）

### Windows 側（必須）

1. [WinCompose](https://github.com/samhocevar/wincompose/releases) をインストール
2. 配列 **英語(米国)**、**IME オフ**
3. タスクバーで **ENG** を選択

QMK が WinCompose 向け Unicode 入力シーケンスを送ります。記号そのものを HID で送っているわけではありません。

### 例: è

`D` → 親指4番目 → `F`（`X(U_E_GRV)` = U+00E8）

## L3 ギリシャ層 対応表（標準ギリシャ語配列）

物理キー（QWERTY）→ ギリシャ文字。

| 段 | キーと文字 |
|----|-----------|
| 上 | W=ς  E=ε  R=ρ  T=τ  Y=υ  U=θ  I=ι  O=ο  P=π |
| 中 | A=α  S=σ  D=δ  F=φ  G=γ  H=η  J=ξ  K=κ  L=λ |
| 下 | Z=ζ  X=χ  C=ψ  V=ω  B=β  N=ν  M=μ |

開き方: `D` 長押し（L2）→ 親指3番目 OSL(3) → 各キー

## 書き込み

`firmware/keyball44-my_keymap/latest.hex`  
https://sekigon-gonnoc.github.io/promicro-web-updater/（左右 flash）
