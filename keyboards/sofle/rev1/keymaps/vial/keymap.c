/* Copyright 2020 Josef Adamcik
 * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
 * Modification for Vial support by Drew Petersen
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

// clang-format off

#include QMK_KEYBOARD_H
#include "oled.c"
#include "layers.h"

// Custom modifier combinations
#define C_S(kc) (QK_LCTL | QK_LSFT | (kc))  // Ctrl+Shift+Key
#define LSA(kc) (QK_LSFT | QK_LALT | (kc))   // Left Shift+Alt+Key

// Default keymap. This can be changed in Vial. Use oled.c to change beavior that Vial cannot change.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY Layer
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Caps |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  Mute |    | Play  |------+------+------+------+------+------|
 * | LCTRL|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | RCTRL|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | Home |Special| /Space  /       \ Enter \  | Dev  | End  | RAlt | RGUI |
 *            |      |      |      |       |/Shift   /         \Shift \ |      |      |      |      |
 *            `-------------------------------------'           '------''--------------------------'
 */
 [_QWERTY] = LAYOUT(
    KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                                 KC_6,     KC_7,     KC_8,     KC_9,    KC_0,    KC_BSPC,
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                                 KC_Y,     KC_U,     KC_I,     KC_O,    KC_P,    KC_GRV,
    KC_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                                 KC_H,     KC_J,     KC_K,     KC_L,    KC_SCLN, KC_QUOT,
    KC_LCTL,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_MUTE,              KC_MPLY,          KC_N,     KC_M,     KC_COMM,  KC_DOT,  KC_SLSH, KC_RCTL,
                       KC_LGUI, KC_LALT, KC_HOME, TG(_SPECIAL), LSFT_T(KC_SPC),       RSFT_T(KC_ENT),   TG(_DEV), KC_END,   KC_RALT,  KC_RGUI
),
/*
 * SPECIAL Layer - Symbols and Shifted Characters
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |Trans |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  | Trans|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Trans |   =  |   -  |   +  |   {  |   }  |                    |   [  |   ]  |   :  |   ;  |   |  |  N/A |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Trans |      |      |      |   \  |   /  |-------.    ,-------|   ?  |   _  |   ~  |      |      |      |
 * |------+------+------+------+------+------|  Mute |    | Play  |------+------+------+------+------+------|
 * |Trans |      |      |      |      |      |-------|    |-------|   <  |   >  |      |      |      | Trans|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |Trans |Trans |Trans |Trans | /       /       \      \  |Trans |Trans | Trans |Trans |
 *            |      |      |      |      |/       /         \      \ |      |      |      |       |
 *            `-----------------------------------'           '------''---------------------------'
 */
 [_SPECIAL] = LAYOUT(
    KC_TRNS,  LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4),    LSFT(KC_5),                           LSFT(KC_6),    LSFT(KC_7),    LSFT(KC_8),   LSFT(KC_9),    LSFT(KC_0),    KC_TRNS,
    KC_TRNS,  KC_EQL,     KC_MINS,    KC_PLUS,    LSFT(KC_LBRC), LSFT(KC_RBRC),                        KC_LBRC,       KC_RBRC,       KC_SCLN,      LSFT(KC_SCLN), LSFT(KC_BSLS), KC_NO,
    KC_TRNS,  KC_NO,      KC_NO,      KC_NO,      KC_BSLS,       KC_SLSH,                              LSFT(KC_SLSH), LSFT(KC_MINS), LSFT(KC_GRV), KC_NO,         KC_NO,         KC_NO,
    KC_TRNS,  KC_NO,      KC_NO,      KC_NO,      KC_NO,         KC_NO,        KC_MUTE,       KC_MPLY, LSFT(KC_COMM), LSFT(KC_DOT),  KC_NO,        KC_NO,         KC_NO,         KC_TRNS,
                          KC_TRNS,    KC_TRNS,    KC_TRNS,       KC_TRNS,      KC_TRNS,       KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS,      KC_TRNS
),
/*
 * DEV Layer - Developer Tools
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |Trans |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F8  |  F9  | F10  | F11  | F12  | Trans|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Trans |CS+S  |Ctl+S |CS+`  |CtlF12|PrtScn|                    | Del  |S+Left|  Up  |S+Right|SA+Up|Ctl+- |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |Trans |Ctl+Z |Ctl+X |Ctl+C |Ctl+V |Ctl+F |-------.    ,-------| Ins  | Left | Down | Right|SA+Dn |Ctl+. |
 * |------+------+------+------+------+------|  Mute |    | Play  |------+------+------+------+------+------|
 * |Trans |Ctl+A |Ctl+D |CS+P  |CS+B  |CS+F  |-------|    |-------| Calc |CtlSpc|      |      |      | Trans|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |Trans |Trans |Trans |Trans | /       /       \      \  |Trans |Trans | Trans |Trans |
 *            |      |      |      |      |/       /         \      \ |      |      |      |       |
 *            `-----------------------------------'           '------''----------------------------'
 */
 [_DEV] = LAYOUT(
    KC_TRNS,  KC_F1,      KC_F2,      KC_F3,       KC_F4,        KC_F5,                                   KC_F8,    KC_F9,         KC_F10,  KC_F11,        KC_F12,       KC_TRNS,
    KC_TRNS,  C_S(KC_S),  LCTL(KC_S), C_S(KC_GRV), LCTL(KC_F12), KC_PSCR,                                 KC_DEL,   LSFT(KC_LEFT), KC_UP,   LSFT(KC_RGHT), LSA(KC_UP),   RCTL(KC_MINS),
    KC_TRNS,  LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C),  LCTL(KC_V),   LCTL(KC_F),                              KC_INS,   KC_LEFT,       KC_DOWN, KC_RGHT,       LSA(KC_DOWN), RCTL(KC_DOT),
    KC_TRNS,  LCTL(KC_A), LCTL(KC_D), C_S(KC_P),   C_S(KC_B),    C_S(KC_F),  KC_MUTE,            KC_MPLY, KC_CALC,  RCTL(KC_SPC),  KC_NO,   KC_NO,         KC_NO,        KC_TRNS,
                          KC_TRNS,    KC_TRNS,     KC_TRNS,      KC_TRNS,    KC_TRNS,            KC_TRNS, KC_TRNS,  KC_TRNS,       KC_TRNS, KC_TRNS
)
};

const uint16_t PROGMEM encoder_map[NUM_ENCODER_LAYERS][NUM_ENCODERS][NUM_ENCODER_DIRECTIONS] = {
    [_QWERTY] = {
        {KC_VOLD, KC_VOLU},  // Left encoder (CCW, CW)
        {KC_MPRV, KC_MNXT}   // Right encoder
    },
    [_SPECIAL] = {
        {KC_TRNS, KC_TRNS},
        {KC_TRNS,   KC_TRNS}
    },
    [_DEV] = {
        {KC_TRNS, KC_TRNS},
        {KC_TRNS, KC_TRNS}
    }
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            // Base layer: Volume control
            if (index == 0) { // Left encoder
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
            } else { // Right encoder
                if (clockwise) {
                    tap_code(KC_MEDIA_NEXT_TRACK);
                } else {
                    tap_code(KC_MEDIA_PREV_TRACK);
                }
            }
            break;
    }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    if (index == 0) { // Left encoder press
        tap_code(KC_MUTE);
    } else { // Right encoder press
        tap_code(KC_MEDIA_PLAY_PAUSE);
    }
    return true;
}
