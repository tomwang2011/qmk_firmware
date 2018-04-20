/* Copyright 2017 Tom
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
#include "xd75.h"

// Layer shorthand
#define _QW 0
#define _FN 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | `      | -      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      |    ~   | [      | ]      | Y      | U      | I      | O      | P      |   \    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | CTRL   | A      | S      | D      | F      | G      | HOME   | PG UP  | ENTER  | H      | J      | K      | L      | ;      | "      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | END    | PG DN  | DEL    | N      | M      | ,      | .      | /      | UP     |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | LGUI   | LALT   | FN     | SPACE  | SPACE  | TGFN   | SPACE  | SPACE  | ENTER  | -      | =      | LEFT   | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QW] = { /* QWERTY */
  { KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_GRV, KC_MINS,  KC_EQL,  KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_BSPC },
  { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_TILD, KC_LBRC, KC_RBRC, KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_BSLS },
  { KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_HOME, KC_PGUP, KC_ENT, KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN,  KC_QUOT },
  { KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,   KC_END,  KC_PGDN, KC_DEL,  KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_UP },
  { KC_LCTL, KC_LGUI, KC_LALT, MO(_FN), KC_SPC, KC_SPC, TG(_QW), KC_SPC,  KC_SPC, KC_ENT, KC_MINS ,KC_EQL, KC_LEFT, KC_DOWN,   KC_RGHT },
 },


/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | SELECT | CALC   | MYCOMP | MAIL   |        |        | P7     | P8     | P9     | -      |        |        | PR SCR | SCR LK | PR SCR |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | CAPS   | PLAY   | NEXT   | STOP   |        |        | P4     | P5     | P6     | +      |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | SHIFT  | MUTE   | VOL+   |        |        |        | P1     | P2     | P3     | PENT   |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | CTRL   |    GUI |   ALT  | FN     |        |        | P0     |        | P.     | PENT   | PENT   | FN     |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_FN] = { /* FUNCTION */
  { KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NLCK, RESET},
  { KC_MSEL, KC_DEL , KC_UP,   BL_TOGG, RGB_TOG, KC_SPC, KC_P7,   KC_P8,   KC_P9,   KC_MINS, KC_SPC,  KC_UP,  KC_TRNS, KC_TRNS, KC_TRNS },
  { KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, RGB_MOD, KC_SPC, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, KC_LEFT, KC_DOWN, KC_RGHT,  KC_P8,  KC_P9 },
  { KC_LSFT, KC_COPY,LCTL(KC_X),LCTL(KC_C),LCTL(KC_V), KC_PASTE, KC_P1,   KC_P2,   KC_P3,   KC_TRNS, KC_SPC,  KC_SPC,  KC_P4,  KC_P5, KC_P6 },
  { KC_LCTL, KC_LGUI, KC_LALT, MO(_FN), KC_SPC, KC_SPC, TG(_QW), KC_KP_0, KC_PDOT, KC_PENT, KC_TRNS, MO(_FN), KC_P1, KC_P2, KC_P3 },
 }
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
