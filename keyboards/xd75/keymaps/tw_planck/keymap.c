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
#define _LW 2
#define _TG 3

#define UNDO LCTL(KC_Z)
#define REDO LSFT(LCTL(KC_Z))
#define TERM LCA(KC_T)
#define TTAB LSFT(LCTL(KC_T))
#define TRST LSFT(LCTL(KC_R))
#define TCPY LSFT(LCTL(KC_C))
#define TPST LSFT(LCTL(KC_V))
#define IJCL LCTL(KC_N)
#define IJFL LSFT(LCTL(KC_N))

enum custom_keycodes {
    PORTAL = SAFE_RANGE,
    TOMCAT,
    GITK,
    GITGUI,
    GITRBI,
    GITPSF,
    GITCMT
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case GITK:
                SEND_STRING("gitk"); // this is our macro!
                return false;
            case GITGUI:
                SEND_STRING("git gui"); // this is our macro!
                return false;
            case GITRBI:
                SEND_STRING("git rebase -i HEAD~20"); // this is our macro!
                return false;
            case PORTAL:
                SEND_STRING("cd /liferaysc/liferay-portal"); // this is our macro!
                return false;
            case TOMCAT:
                SEND_STRING("cd /home/tom/tomcat"); // this is our macro!
                return false;
            case GITPSF:
                SEND_STRING("git push -f ");
                return false;
            case GITCMT:
                SEND_STRING("git commit -m\"");
                return false;
        }
    }
    return true;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | `      | UNDO   | REDO   | 6      | 7      | 8      | 9      | 0      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      |  TERM  | [      | ]      | Y      | U      | I      | O      | P      |   \    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | CTRL   | A      | S      | D      | F      | G      | HOME   | PG UP  | ENTER  | H      | J      | K      | L      | ;      | "      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | END    | PG DN  | DEL    | N      | M      | ,      | .      | /      | UP     |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | HYPR   | LCTRL  | LGUI   | LALT   | FN     | SPACE  | TG     | SPACE  | SPACE  | ENTER  | LW     | -      | LEFT   | DOWN   | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QW] = { /* QWERTY */
  { KC_GESC, KC_1,    KC_2,       KC_3,       KC_4,       KC_5,     KC_GRV,    UNDO,      REDO,     KC_6,     KC_7,     KC_8,       KC_9,     KC_0,     KC_BSPC },
  { KC_TAB,  KC_Q,    KC_W,       KC_E,       KC_R,       KC_T,     TERM,      KC_LBRC,   KC_RBRC,  KC_Y,     KC_U,     KC_I,       KC_O,     KC_P,     KC_BSLS },
  { KC_LCTL, KC_A,    KC_S,       KC_D,       KC_F,       KC_G,     KC_HOME,   KC_PGUP,   KC_ENT,   KC_H,     KC_J,     KC_K,       KC_L,     KC_SCLN,  KC_QUOT },
  { KC_LSPO, KC_Z,    KC_X,       KC_C,       KC_V,       KC_B,     KC_END,    KC_PGDN,   KC_DEL,   KC_N,     KC_M,     KC_COMM,    KC_DOT,   KC_SLSH,  KC_RSPC },
  { KC_HYPR, KC_LCTL, KC_LGUI,    KC_LALT,    MO(_FN),    KC_SPC,   KC_SPC,    MO(_TG),   KC_SPC,   KC_ENT,   MO(_LW),  KC_MINS,    KC_LEFT,  KC_DOWN,  KC_RGHT },
 },

 [_FN] = { /* FUNCTION */
  { KC_TRNS, KC_F1,   KC_F2,      KC_F3,      KC_F4,          KC_F5,          KC_F6,     KC_F7,     KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_TRNS,  KC_TRNS},
  { KC_TRNS, KC_EXLM, KC_UP,      KC_HASH,    KC_DLR,         KC_PERC,        PORTAL,    TOMCAT,    GITPSF,   KC_CIRC,  KC_AMPR,  KC_ASTR,    KC_MINS,  KC_EQL,   KC_TRNS},
  { KC_TRNS, KC_LEFT, KC_DOWN,    KC_RGHT,    LCTL(KC_MINS),  LCTL(KC_EQL),   TTAB,      GITRBI,    GITCMT,   KC_4,     KC_5,     KC_6,       KC_PGUP,  KC_PGDN,  KC_ENT },
  { KC_TRNS, UNDO   , LCTL(KC_X), LCTL(KC_C), LCTL(KC_V),     REDO,           TCPY,      IJCL,      IJFL,     KC_1,     KC_2,     KC_3,       KC_HOME,  KC_UP,    KC_END },
  { KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    MO(_FN),        KC_SPC,         KC_SPC,    MO(_TG),   KC_SPC,   KC_ENT,   MO(_LW),  KC_DEL,     KC_LEFT,  KC_DOWN,  KC_RGHT},
 },

 [_LW] = { /* Lower */
  { KC_TRNS, KC_F1,   KC_F2,      KC_F3,      KC_F4,          KC_F5,          KC_F6,     KC_F7,     KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_TRNS,  KC_TRNS},
  { KC_TRNS, KC_EXLM, KC_UP,      KC_HASH,    KC_DLR,         KC_PERC,        PORTAL,    TOMCAT,    GITPSF,   KC_CIRC,  KC_AMPR,  KC_ASTR,    KC_MINS,  KC_EQL,   KC_TRNS},
  { KC_TRNS, KC_LEFT, KC_DOWN,    KC_RGHT,    LCTL(KC_MINS),  LCTL(KC_EQL),   TTAB,      GITRBI,    GITCMT,   KC_4,     KC_5,     KC_6,       KC_PGUP,  KC_PGDN,  KC_ENT },
  { KC_TRNS, UNDO   , LCTL(KC_X), LCTL(KC_C), LCTL(KC_V),     REDO,           TRST,      TCPY,      TPST,     KC_1,     KC_2,     KC_3,       KC_HOME,  KC_UP,    KC_END },
  { KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    MO(_FN),        KC_SPC,         KC_SPC,    MO(_TG),   KC_SPC,   KC_ENT,   MO(_LW),  KC_DEL,     KC_LEFT,  KC_DOWN,  KC_RGHT},
 },

 /* Toggle
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    | F12    | NUM LK | RESET  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | SELECT | DEL    | UP     | BL TOG | RGB TOG| SPACE  | PORTAL | TOMCAT | GITGUI | -      |        |  UP    |        | [      | ]      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | CAPS   | LEFT   | DOWN   | RGHT   |        | SPACE  | P4     | P5     | GITK   | +      |  LEFT  | Down   | RIGHT  |        | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | SHIFT  | COPY   | CTRLX  | CTRLC  | CTRLV  | PASTE  | P1     | P2     | P3     | PENT   |        |        |        |        | SFT    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | CTRL   |    GUI |   ALT  | FN     | SPACE  | SPACE  | QW     | P0     | P.     | FN     | ALT    | CTRL   |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_TG] = { /* Toggle */
  { KC_TRNS,  KC_F1,   KC_F2,      KC_F3,      KC_F4,      KC_F5,  KC_F6,     KC_F7,    KC_F8,    KC_F9,    KC_F10,  KC_F11,    KC_F12,   RESET,    KC_TRNS},
  { KC_TRNS, KC_DEL , KC_UP,      BL_TOGG,    RGB_TOG,    KC_SPC, PORTAL,    TOMCAT,   GITPSF,   KC_7,     KC_8,     KC_9,     KC_TRNS,  KC_LBRC,  KC_RBRC},
  { KC_TRNS, KC_LEFT, KC_DOWN,    KC_RGHT,    RGB_MOD,    KC_SPC, TTAB,      GITRBI,   GITCMT,   KC_4,     KC_5,     KC_6,     KC_PGUP,  KC_PGDN,  KC_DEL },
  { KC_TRNS, UNDO   , LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), REDO,   TCPY,      IJCL,     IJFL,     KC_1,     KC_2,     KC_3,     KC_HOME,  KC_UP,    KC_END },
  { KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    MO(_FN),    KC_SPC, KC_SPC,    MO(_TG),  KC_SPC,   KC_ENT,   MO(_LW),  KC_DEL,   KC_LEFT,  KC_DOWN,  KC_RGHT},
 },
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
