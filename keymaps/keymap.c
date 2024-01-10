// Copyright 2023 Qmk
// SPDX-License-Identifier: GPL-2.0-or-later
 
#include QMK_KEYBOARD_H
#include "features/caps_word.h"

bool process_record_user(uint16_t keycode, keyrecord_t* record){
	if(!process_caps_word(keycode, record)) {return false;}
	//macros here
	return true;
}

#define QWERTY 0 // Base qwerty
#define NUMPAD 1 // second layer


/****************************************************************************************************
*
* Keymap: Default Layer in Qwerty
*
* ,-------------------------------------------------------------------------------------------------------------------.
* | CAPS   |  F1  |  F2  |  F3  |  F4  |  F5  | |  F6  | F7   |  F8  |  F9  |  F10 |  F11  |F12|PSCR| SLCK| PAUS |FN0|BOOT
* | F12    |  F1  |  F2  |  F3  |  F4  |  F5  |PSCR| SLCK| PAUS |FN0|BOOT |  F6  | F7   |  F8  |  F9  |  F10 |  F11   |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* | =+     |  1!  |  2@  |  3#  |  4$  |  5%  |                           |  6^  |  7&  |  8*  |  9(  |  0)  | -_     |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* | Tab    |   Q  |   W  |   E  |   R  |   T  |                           |   Y  |   U  |   I  |   O  |   P  | \|     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | ESC    |   A  |   S  |   D  |   F  |   G  |                           |   H  |   J  |   K  |   L  |  ;:  | '"     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Shift  |   Z  |   X  |   C  |   V  |   B  |                           |   N  |   M  |  ,.  |  .>  |  /?  | Shift  |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          | `~   | INS  | Left | Right|                                         | Down | UP   |  [{  |  ]}  |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        | Ctrl | Alt  |         | Gui  | CMD-ESC |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      | Home |         | PgUp |      |      |
*                                 | BkSp | Del  |------|         |------|Return| Space|
*                                 |      |      | End  |         | PgDn |      |      |
*                                 `--------------------'         `--------------------'
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [QWERTY] = LAYOUT(
        KC_CAPS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5, KC_F6,    KC_F7,    KC_F8,                          KC_F9,    KC_F10,   KC_F11, KC_F12,  KC_PSCR,  KC_SCRL,  KC_PAUS, TG(1),QK_BOOT,
        KC_EQL,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                                                                      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                                                                      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
LCTL_T(KC_ESC),   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                                                                      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
       KC_LSFT,   KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                                                                      KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
                KC_GRV,   KC_INS,   KC_LEFT,  KC_RGHT,                                                                                       KC_DOWN,    KC_UP,  KC_LBRC,  KC_RBRC,
                                                      KC_LCTL,  KC_LALT,                                               KC_RGUI,  RCMD_T(KC_ESC),
                                                                KC_HOME,                                               KC_PGUP,
                                            KC_BSPC,  KC_DEL,   KC_END,                                                KC_PGDN,  KC_ENTER, KC_SPC
  ),


  [NUMPAD] = LAYOUT(
            KC_CAPS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5, KC_F6,    KC_F7,    KC_F8,                          KC_F9,    KC_F10,   KC_F11, KC_F12,  KC_MUTE,  KC_VOLD,  KC_VOLU, KC_TRNS,QK_BOOT,
            KC_EQL,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                                                                     KC_NO,    KC_7,     KC_PEQL,  KC_PSLS,  KC_PAST,     KC_MINS,
            KC_TAB,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                                                                    KC_NO,    KC_7,     KC_8,     KC_9,     KC_PMNS,     KC_BSLS,
    LCTL_T(KC_ESC),   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                                                                    KC_NO,    KC_4,     KC_5,     KC_6,     KC_PPLS,     KC_QUOT,
           KC_LSFT,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                                                                    KC_NO,    KC_1,     KC_2,     KC_3,     KC_ENTER,    KC_RSFT,
                      KC_GRV,   KC_INS,   KC_LEFT,  KC_RGHT,                                                                                      KC_DOWN,  KC_UP,    KC_PDOT,  KC_ENTER,
                                                      KC_LCTL,  KC_LALT,                                               KC_RGUI,  RCMD_T(KC_ESC),
                                                                KC_HOME,                                               KC_PGUP,
                                            KC_BSPC,  KC_DEL,   KC_END,                                                KC_PGDN,  KC_ENTER, KC_0
  )

};
