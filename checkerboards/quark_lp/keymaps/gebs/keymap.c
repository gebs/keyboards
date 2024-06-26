/* Copyright 2021 Nathan Spears
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


enum planck_layers {
  _QWERTY,
  _SHIFT,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NAV
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define SHIFT MO(_SHIFT)
#define NAV MO(_NAV)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* [0]
     * ,-----------------------------------------------------------------------------------------.
     * |------------+------+------+------+------+------+------+------+------+------+------+------|
     * | Tab        |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
     * |------------+------+------+------+------+-------------+------+------+------+------+------|
     * | CTL & ESC  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
     * |------------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift      |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
     * |-------+-------+-------+-------+-------+-------+------+------+------+------+------+------|
     * | PRINT   |  OS   |  Alt  |  Layer  |    Space & Layer     |   [     |   ]    |    CAPS   |
     * `-----------------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_ortho_4x12(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Z,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, S(KC_QUOT),
        SHIFT,   KC_Y,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
        KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

    /* [1]
     * ,---------------------------------------------------------------------------------------.
     * |------------+------+------+------+------+------+------+------+------+------+------+----|
     * |   ~    | !    |  @   |  #  |  $   |  %   |  | ^  |  &   |  *  |  (    |  )  | BCKSPC  |
     * |------------+------+------+------+------+-------------+------+------+------+------+----|
     * |   \    |    1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   /   |
     * |------------+------+------+------+------+------|------+------+------+------+------+----|
     * |     |      |      |      |      |      |      |   +   |   =   |      |        |       |
     * |-------+-------+-------+-------+-------+-------+------+------+------+------+------+----|
     * |   ESC  |  CTRL-ALT-DEL   |   TASK   |         |        |    '|'    |    `    |        |
     * `---------------------------------------------------------------------------------------'
     */
    [_SHIFT] = LAYOUT_ortho_4x12(
        KC_TILD, S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T), S(KC_Z), S(KC_U), S(KC_I),    S(KC_O),  S(KC_P),   KC_DEL,
        _______, S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G), S(KC_H), S(KC_J), S(KC_K),    S(KC_L),  S(KC_SCLN),KC_QUOT,
        _______, S(KC_Y), S(KC_X), S(KC_C), S(KC_V), S(KC_B), S(KC_N), S(KC_M), S(KC_COMM), S(KC_DOT),S(KC_SLSH),S(KC_ENT) ,
        KC_LCTL, _______, _______, KC_LPRN, KC_RPRN, KC_SPC,  KC_SPC,  _______, KC_HOME,    KC_PGDN,  KC_PGUP ,  KC_END
    ),

    [_LOWER] = LAYOUT_ortho_4x12(
        KC_TILD, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,  KC_7,   KC_8,   KC_9,    _______, _______,
        KC_DEL,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_LCBR, KC_RCBR,  KC_4,   KC_5,   KC_6,    KC_DOT, _______,
        KC_LSFT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_LBRC, KC_RBRC,  KC_1,   KC_2,   KC_3,    KC_UP, _______,
        _______, _______, _______, _______, LOWER,   _______, _______,  RAISE,  KC_0,   KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /* [2]
    * ,---------------------------------------------------------------------------------------.
    * |------------+------+------+------+------+------+------+------+------+------+------+---|
    * |       |      |      |  UP  |       |      |     |   _   |     |   [   |  ]    |      |
    * |------------+------+------+------+------+-------------+------+------+------+------+---|
    * |       |     | LEFT | DOWN  | RIGHT |     |      |   -  |      |   [   |   ]   |      |
    * |------------+------+------+------+------+-----+-----+------+------+------+------+-----|
    * |   F1  | F2 |  F3  |   F4  | F5    | F6  | F7   | F8   | F9    | F10  | F11   | F12   |
    * |-------+-------+-------+-------+-------+-------+------+------+------+------+------+---|
    * |     RESET    |           |          |         |         |         |        |         |
    * `---------------------------------------------------------------------------------------'
       */
    [_RAISE] = LAYOUT_ortho_4x12(
        _______,  _______,    _______, _______, _______, _______, _______, RALT(KC_Y), _______, RALT(KC_P), _______, _______,
        _______,  RALT(KC_Q), KC_EXLM, KC_AT,   KC_BSLS, KC_MINS, KC_ASTR, KC_EQL,  KC_AMPR, KC_PERC, _______, _______,
        _______,  _______,    _______, KC_CIRC, KC_HASH, KC_UNDS, KC_PLUS, KC_PIPE, KC_DLR,  _______, _______, _______,
        _______,  _______,    _______, _______, LOWER  , _______, _______, RAISE, _______, _______, _______, _______
    ),   

    [_ADJUST] = LAYOUT_ortho_4x12(
        _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
        _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, AG_NORM, AG_SWAP, KC_MPLY, KC_MPRV,  KC_MNXT, KC_MSTP,  _______,
        _______, MUV_DE,  LALT(KC_F4),  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
    )

};
