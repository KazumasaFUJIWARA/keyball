/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

// L2: F/G=language; thumb L33-L35=OSL(3/4/5) (replaces L2 全角半角 dup).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_ESC   , KC_Q     , KC_W     , 0x2108   , KC_R     , KC_T     ,                                        KC_Y     , KC_U     , 0x310C   , KC_O     , KC_P     , KC_BSPC  ,
    KC_TAB   , 0x2104   , 0x2416   , 0x4207   , 0x4109   , 0x460A   ,                                        0x460B   , 0x410D   , 0x420E   , 0x240F   , 0x3133   , 0x0034   ,
    0x00D3   , 0x281D   , 0x231B   , KC_C     , KC_V     , KC_B     ,                                        KC_N     , KC_M     , KC_COMM  , KC_DOT   , 0x2838   , 0x0087   ,
              0x0088   , 0x0091   , 0x00D2   , 0x00D1   , 0x222C   ,                                        KC_ENT   , KC_LSFT  , 0x004C
  ),

  [1] = LAYOUT(
    0x00A8   , 0x001E   , 0x001F   , 0x0020   , 0x0021   , 0x0022   ,                                        0x0023   , 0x0024   , 0x0025   , 0x0026   , 0x0027   , 0x002E   ,
    0x0282   , KC_TAB   , 0x0450   , 0x012B   , 0x032B   , 0x144F   ,                                        0x0050   , 0x0051   , 0x0052   , 0x004F   , 0x002D   , 0x0045   ,
    0x00AA   , 0x00DB   , 0x0850   , 0x0852   , 0x0851   , 0x01E3   ,                                        0x0450   , 0x0080   , 0x00AE   , 0x044F   , _______  , _______  ,
              _______  , 0x00DA   , KC_ESC   , KC_BSPC  , 0x004C   ,                                        KC_NO    , KC_NO    , _______
  ),

  [2] = LAYOUT(
    _______  , 0x021E   , 0x021F   , 0x0220   , 0x0221   , 0x0222   ,                                        0x0223   , 0x0224   , 0x0225   , 0x0226   , 0x022E   , _______  ,
    _______  , 0x002F   , 0x002E   , 0x0289   , 0x0090   , 0x0091   ,                                        KC_NO    , 0x022F   , 0x0230   , 0x0231   , 0x022D   , 0x021F   ,
    _______  , KC_NO    , KC_NO    , 0x0149   , 0x0249   , KC_NO    ,                                        KC_NO    , KC_NO    , 0x0030   , 0x0031   , 0x0238   , 0x0289   ,
              0x0027   , KC_DOT   , OSL(3)   , OSL(4)   , OSL(5)   ,                                        0x0950   , 0x094F   , _______
  ),

  // L3: Greek (lowercase Unicode)
  [3] = LAYOUT(
    _______  , _______  , UC(0x03B5), UC(0x03C1), UC(0x03C4), UC(0x03C5),                                        UC(0x03B8), UC(0x03B9), UC(0x03BF), UC(0x03C0), UC(0x03C9), _______  ,
    _______  , UC(0x03B1), UC(0x03C3), UC(0x03B4), UC(0x03C6), UC(0x03B3),                                        UC(0x03B7), UC(0x03BE), UC(0x03BA), UC(0x03BB), _______  , _______  ,
    _______  , UC(0x03B6), UC(0x03C7), UC(0x03C8), UC(0x03C9), UC(0x03B2),                                        UC(0x03BD), UC(0x03BC), _______  , _______  , _______  , _______  ,
              _______  , _______  , _______  , _______  , _______  ,                                        _______  , _______  , _______
  ),

  // L4: Italian accented vowels
  [4] = LAYOUT(
    _______  , _______  , _______  , UC(0x00E9), _______  , _______  ,                                        _______  , UC(0x00F9), UC(0x00EC), UC(0x00F2), UC(0x00E1), _______  ,
    _______  , UC(0x00E0), _______  , _______  , UC(0x00E8), _______  ,                                        _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                        _______  , _______  , _______  , _______  , _______  , _______  ,
              _______  , _______  , _______  , _______  , _______  ,                                        _______  , _______  , _______
  ),

  // L5: Math symbols (Unicode)
  [5] = LAYOUT(
    _______  , UC(0x00B1), UC(0x00D7), UC(0x00F7), UC(0x2260), UC(0x2248),                                        UC(0x2264), UC(0x2265), UC(0x221E), UC(0x03C0), UC(0x00B0), _______  ,
    _______  , UC(0x2200), UC(0x2203), UC(0x2208), UC(0x2211), UC(0x222B),                                        UC(0x221A), UC(0x2202), UC(0x2207), UC(0x2282), UC(0x2229), _______  ,
    _______  , UC(0x2205), UC(0x222A), UC(0x2295), UC(0x2192), UC(0x2190),                                        UC(0x2194), UC(0x21D2), UC(0x21D4), UC(0x22A5), UC(0x2220), _______  ,
              _______  , _______  , _______  , _______  , _______  ,                                        _______  , _______  , _______
  ),

  // L6: Settings / RGB / Keyball
  [6] = LAYOUT(
    0x7820   , 0x003A   , 0x003B   , 0x003C   , 0x003D   , 0x003E   ,                                        0x003F   , 0x0040   , 0x0041   , 0x0042   , 0x0043   , 0x0044   ,
    0x7821   , 0x7823   , 0x7825   , 0x7827   , _______  , 0x7E08   ,                                        0x7831   , 0x7832   , 0x7833   , 0x7834   , _______  , _______  ,
    0x7822   , 0x7824   , 0x7826   , 0x7828   , SCRL_DVI , 0x7E09   ,                                        0x7E05   , 0x7E03   , 0x7E02   , 0x7E04   , _______  , 0x7E01   ,
              0x7C00   , 0x7E00   , _______  , _______  , _______  ,                                        _______  , _______  , 0x7C00
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    keyball_set_scroll_mode(get_highest_layer(state) == 6);
    return state;
}

void keyboard_post_init_user(void) {
#ifdef UNICODE_ENABLE
    set_unicode_input_mode(UNICODE_MODE_WINDOWS);
#endif
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
