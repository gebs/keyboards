/* Copyright 2017 Wunder
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum layer_names {
    _QW,
    _SHIFT,
    _LOWER,
    _RAISE,
    _ADJUST,
    _FN
};


#define SHIFT MO(_SHIFT)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FN MO(_FN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | `      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | TAB    | Q      | W      | E      | R      | T      | [      | \      | ]      | Y      | U      | I      | O      | P      | '      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | CAP LK | A      | S      | D      | F      | G      | HOME   | DEL    | PG UP  | H      | J      | K      | L      | ;      | ENTER  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      | END    | UP     | PG DN  | N      | M      | ,      | .      | /      | RSHIFT |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
     * | LCTRL  | LGUI   | LALT   | FN     | SPACE  | SPACE  | LEFT   | DOWN   | RIGHT  | SPACE  | SPACE  | FN     | RALT   | RGUI   | RCTRL  |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_QW] = LAYOUT_ortho_5x15( /* QWERTY */
        KC_TILD,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,     KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Z,    KC_U,    KC_I,    KC_O,    KC_P,    KC_ENT,      KC_P7,    KC_P8,    KC_P9,
        KC_ESC,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, S(KC_QUOT),  KC_P4,    KC_P5,    KC_P6,
        SHIFT,    KC_Y,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,       KC_P1,    KC_P2,    KC_P3,
        KC_LCTL,  KC_LSFT, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   FN,      KC_SPC,  KC_LEFT, KC_DOWN,     KC_RGHT,  KC_P0,    KC_PDOT
    ),


    [_SHIFT] = LAYOUT_ortho_5x15( /* QWERTY */
        _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,       KC_9,     KC_0,      KC_DEL,      KC_9,    KC_0,    KC_BSPC,
        _______,  S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T), S(KC_Z), S(KC_U), S(KC_I),    S(KC_O),  S(KC_P),   S(KC_ENT),   KC_7,    KC_8,    KC_9,
        _______,  S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G), S(KC_H), S(KC_J), S(KC_K),    S(KC_L),  S(KC_SCLN),KC_QUOT,     KC_4,    KC_5,    KC_6,
        _______,  S(KC_Y), S(KC_X), S(KC_C), S(KC_V), S(KC_B), S(KC_N), S(KC_M), S(KC_COMM), S(KC_DOT),S(KC_SLSH),KC_UP,       KC_1,    KC_2,    KC_3,
        KC_LCTL,  _______, _______, KC_LPRN, KC_RPRN, KC_SPC,  KC_SPC,  _______, KC_HOME,    KC_SPC,   KC_LEFT,   KC_DOWN,     KC_RGHT, KC_0,    KC_DOT
    ),

    [_LOWER] = LAYOUT_ortho_5x15( /* QWERTY */
        _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______,    _______,    _______,
        _______,  KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_7,    KC_8,    KC_9,    _______, _______,     _______,    _______,    _______,
        _______,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_LCBR, KC_RCBR, KC_4,    KC_5,    KC_6,    KC_DOT,  _______,     _______,    _______,    _______,
        _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_LBRC, KC_RBRC, KC_1,    KC_2,    KC_3,    KC_UP,   _______,     _______,    _______,    _______,
        _______,  _______, _______, _______, LOWER,   _______, _______, RAISE,   KC_0,    KC_LEFT, KC_DOWN, _______,     _______,    _______,    _______
    ),


    [_RAISE] = LAYOUT_ortho_5x15( /* QWERTY */
        _______,  _______,    _______, _______, _______, _______, _______, _______,    _______, _______,    _______, _______, _______,  _______,    _______,
        _______,  _______,    _______, _______, _______, _______, _______, RALT(KC_Y), _______, RALT(KC_P), _______, _______, _______,  _______,    _______,
        _______,  RALT(KC_Q), KC_EXLM, KC_AT,   KC_BSLS, KC_MINS, KC_ASTR, KC_EQL,     KC_AMPR, KC_PERC,    _______, _______, _______,  _______,    _______,
        _______,  _______,    _______, KC_CIRC, KC_HASH, KC_UNDS, KC_PLUS, KC_PIPE,    KC_DLR,  _______,    _______, _______, _______,  _______,    _______,
        _______,  _______,    _______, _______, LOWER  , _______, _______, RAISE,      _______, _______,    _______, _______, _______,  _______,    _______
    ),


    /* FUNCTION
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | SELECT | CALC   | MYCOMP | MAIL   | RGB HD | RGB HI | P7     | P8     | P9     | -      |        |        | PR SCR | SCR LK | PAUSE  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | PREV   | PLAY   | NEXT   | STOP   | RGB SD | RGB SI | P4     | P5     | P6     | +      |        | RESET  |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | VOL-   | MUTE   | VOL+   | APP    | RGB VD | RGB VI | P1     | P2     | P3     | PENT   |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        | RGB TG | FN     | RGB RMD| RGB MD | P0     |        | P.     | PENT   | PENT   | FN     |        |        |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_FN] = LAYOUT_ortho_5x15( /* FUNCTION */
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_NLCK, KC_SLSH, KC_ASTR, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_MSEL, KC_CALC, KC_MYCM, KC_MAIL, RGB_HUD, RGB_HUI, KC_P7,   KC_P8,   KC_P9,   KC_MINS, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS,
        KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, RGB_SAD, RGB_SAI, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, _______, RESET,   _______, _______, _______,
        KC_VOLD, KC_MUTE, KC_VOLU, KC_APP,  RGB_VAD, RGB_VAI, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______, _______, _______, _______, _______,
        _______, _______, RGB_TOG, MO(_FN), RGB_RMOD,RGB_MOD, KC_P0,   _______, KC_PDOT, KC_PENT, KC_PENT, MO(_FN), _______, _______, _______
    )
};
