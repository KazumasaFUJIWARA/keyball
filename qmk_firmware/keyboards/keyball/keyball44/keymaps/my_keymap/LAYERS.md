# Keyball44 my_keymap — レイヤー対応表

QMK のレイヤー番号は **0 始まり** です（L0, L1, L2 …）。

## レイヤー一覧

| QMK | 名称 | 開き方 |
|-----|------|--------|
| **L2** | 記号・言語 | L0 **D** 長押し |
| **L3** | ギリシャ | L2 + **OSL(3)**（下段左・旧 KC_NO） |
| **L4** | イタalia語 | L2 + **OSL(4)** |
| **L5** | 数学記号 | L2 + **OSL(5)** |
| **L6** | 設定 | L0 **G/H** 長押し |

## L2 の操作（記号は Remap どおり維持）

| キー | 機能 |
|------|------|
| **F / G** | 日本語 / 英数 |
| **下段・L21**（L0 の 0x281D 位置） | OSL(3) ギリシャ |
| **下段・L22**（L0 の 0x231B 位置） | OSL(4) イタalia |
| **下段・L25**（L0 の B 位置、L2 では旧 KC_NO） | OSL(5) 数学 |

**OSL（ワンショット）:** タップ1回で次の1キーだけ L3/L4/L5 になる。MO とは違い、OSL キーを離してから文字キーを押してよい。

### ギリシャ（α）の手順

1. **D** を押す（L2）
2. **OSL(3) キー**をタップ（下段左・2番目付近）
3. **D を離してよい**
4. ホーム行 **2番目**（L0 の 0x2104 位置）→ α

### Unicode が出ないとき（Windows）

- **英数（IME オフ）** にしてから試す（かな入力中は Alt 系 Unicode が効かないことがある）
- **テンキー NumLock ON**
- メモ帳など Windows アプリで試す（WSL ターミナルでは動作が異なる）

## ビルド・書き込み

```bash
bin/fetch-firmware.sh keyball44 my_keymap
```

https://sekigon-gonnoc.github.io/promicro-web-updater/  
`firmware/keyball44-my_keymap/latest.hex` を **左右両方** flash
