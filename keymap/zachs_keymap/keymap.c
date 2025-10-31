/* TEMPLATE
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

#include QMK_KEYBOARD_H
#include "version.h"

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

// Layer Keys
#define SPACE_LT LT(SYMB, KC_BSPC)

enum layers {
    BASE,  // default layer
    SYMB,  // symbols
    NUMPAD,
    RPG,  // RPG
    SATISFACTORY,
    PASS,  // Passwords
};

enum custom_keycodes {
    NTID_UP = SAFE_RANGE,
    NTID_JUST_P,
    ENUMBER,
    PIN,
    WORK_PW,
    HOME_PW,
    RESW,
    HOME,
    POSTGRES,
};


// Per-key tapping-term
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_D:
            return TAPPING_TERM - 50;
        case HOME_K:
            return TAPPING_TERM - 50;
        case SPACE_LT:
            return TAPPING_TERM + 50;
        case HOME_S:
            return TAPPING_TERM + 50;
        case HOME_L:
            return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
}

// Password Macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case NTID_UP:
                SEND_STRING("e441143"SS_TAP(X_TAB)"456rtyfgh$%^RTYFGH"SS_TAP(X_ENT));
                return false;
                break;
            case ENUMBER:
                SEND_STRING("e441143");
                return false;
                break;
            case NTID_JUST_P:
                SEND_STRING("456rtyfgh$%^RTYFGH");
                return false;
                break;
            case PIN:
                SEND_STRING("42839585");
                return false;
                break;
            case WORK_PW:
                SEND_STRING("517531jj"SS_TAP(X_ENT));
                return false;
                break;
            case HOME_PW:
                SEND_STRING("publicstatic"SS_TAP(X_ENT));
                return false;
                break;
            case RESW:
                SEND_STRING("relay"SS_TAP(X_TAB)"s0ftware!"SS_TAP(X_ENT));
                return false;
                break;
            case HOME:
                SEND_STRING("~/");
                return false;
                break;
            case POSTGRES:
                SEND_STRING("postgres"SS_TAP(X_ENT));
                return false;
                break;

        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }

    return state;
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | MAKE |           |      |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;   |   '    |  <-- Home row mods [gui-A, alt-S, shift-D, ctrl-F, ... ctrl-J, shift-K, alt-L, gui-:]
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CAPS_W |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | CAPS_W |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      | HOME |  END | LEFT | RIGHT|                                       | DOWN |  UP  |   [  |   ]  |    `   |
 *   `----------------------------------'                                       `------------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | RPG  | SATIS|       | PGUP | PGDN |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 | BkSp |  DEL |------|       |------| Enter  |Space |
 *                                 |(SYMB)|(NUM) |      |       | PASS |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox_pretty(
  // left hand
  KC_EQL,          KC_1,          KC_2,          KC_3,          KC_4,             KC_5,    QK_MAKE,                DT_PRNT,  KC_6,    KC_7,         KC_8,         KC_9,         KC_0,            KC_MINS,
  KC_TAB,          KC_Q,          KC_W,          KC_E,          KC_R,             KC_T,    KC_NO,                  DT_UP,    KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,            KC_BSLS,
  KC_ESC,          HOME_A,        HOME_S,        HOME_D,        HOME_F,           KC_G,                                      KC_H,    HOME_J,       HOME_K,       HOME_L,       HOME_SCLN,       KC_QUOT,
  CW_TOGG,         KC_Z,          KC_X,          KC_C,          KC_V,             KC_B,    KC_NO,                  DT_DOWN,  KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,         CW_TOGG,
  KC_NO,           KC_HOME,       KC_END,        KC_LEFT,       KC_RIGHT,                                                             KC_DOWN,      KC_UP,        KC_LBRC,      KC_RBRC,         KC_GRV,

                                                                 TG(RPG),TG(SATISFACTORY),                    KC_PGUP, KC_PGDN,
                                                                                    KC_NO,                    KC_NO,
                                                      SPACE_LT, LT(NUMPAD, KC_DEL), KC_NO,                    MO(PASS), KC_ENT, KC_SPC
),
/* Keymap 1: Symbol/Arrow Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 | F12  |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |    `    |   !  |   @  |   #  |   $  |   %  |      |           |      |   ^  |   &  |   *  |   -  |   =  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |    ~/   |      |      |      |      |      |------|           |------|      |   [  |   ]  |   _  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |   {  |   }  |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,
  KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_TRNS,     KC_TRNS, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,  KC_TRNS,
  HOME,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_LBRC, KC_RBRC, KC_UNDS, KC_PLUS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 1: Numpad Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |  BSPC|   /  |   *  |  -   |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |  Tab    |   !  |   @  |   {  |   }  |   |  |      |           |      |      |   7  |   8  |   9  |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+  +   +--------|
 * |   ~/    |   #  |   $  |   (  |   )  |   `  |------|           |------|      |   4  |   5  |   6  |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Shift  |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |      |   1  |   2  |   3  |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+  Ent +--------'
 *   | EPRM  |      |      |      |      |                                       |      0      |   .  |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Del  |      |       |      |      |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |Super |------|       |------| Enter  |Space |
 *                                 |      |      | Esc  |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[NUMPAD] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_BSPC, KC_SLSH,  KC_MINS, KC_TRNS,  KC_TRNS,
  KC_TAB,  KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,     KC_TRNS, KC_TRNS, KC_7,    KC_8,    KC_9,     KC_PLUS, KC_TRNS,
  HOME,    KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                        KC_TRNS, KC_4,    KC_5,    KC_6,     KC_PLUS, KC_TRNS,
  KC_LSFT, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,     KC_TRNS, KC_TRNS, KC_1,    KC_2,    KC_3,     KC_ENT,  KC_TRNS,
  EE_CLR,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_0,    KC_0,    KC_DOT,   KC_ENT,  KC_TRNS,
                                               KC_DEL,  KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_LGUI, KC_ESC,      KC_TRNS, KC_ENT,  KC_SPC
),
/* Keymap 1:  RPG Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * | Windows |  1   |  2   |  3   |  4   |  5   |      |           |   K  |  F6  |  F7  |  F8  |  F9  | F10  |  F11   |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |  Tab    |   Q  |   W  |   E  |   R  |   T  |  J   |           |   L  |   Y  |   U  |   I  |   O  |  P   |  F12   |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  NOOP   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;   |        |
 * |---------+------+------+------+------+------|  I   |           |   N  |------+------+------+------+------+--------|
 * |  Shift  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  ?   |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | CTRL  |   K  |   N  |   O  |  Alt |                                       |  F1  |  F2  |  F3  |  F4  |  F5  |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |GameTG|      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |Space | Map  |------|       |------| Enter|      |
 *                                 |      |      | Esc  |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[RPG] = LAYOUT_ergodox_pretty(
  // left hand
  KC_LGUI,         KC_1,        KC_2,          KC_3,        KC_4,    KC_5,    KC_TRNS,                  KC_K,     KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,    KC_F11,
  KC_TAB,          KC_Q,        KC_W,          KC_E,        KC_R,    KC_T,    KC_J,                     KC_L,     KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,      KC_F12,
  KC_TRNS,         KC_A,        KC_S,          KC_D,        KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,   KC_TRNS,
  KC_LSFT,         KC_Z,        KC_X,          KC_C,        KC_V,    KC_B,    KC_I,                     KC_N,     KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,   KC_TRNS,
  KC_LCTL,         KC_K,        KC_N,          KC_O,        KC_LALT,                                                       KC_F1,   KC_F2,   KC_F3,    KC_F4,     KC_F5,

                                                                 KC_TRNS, KC_LGUI,                  TG(RPG), KC_TRNS,
                                                                          KC_TRNS,                  KC_TRNS,
                                                         KC_SPC, KC_M,    KC_ESC,                   KC_TRNS, KC_ENT, KC_TRNS
),

/* Keymap 4:  Satisfactory Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * | Windows |  1   |  2   |  3   |  4   |  5   |      |           |   K  |   6  |   7  |   8  |   9  |  0   |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |  Tab    |   Q  |   W  |   E  |   R  |   T  |  J   |           |   L  |   Y  |   U  |   I  |   O  |  P   |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  NOOP   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;   |        |
 * |---------+------+------+------+------+------|  I   |           |   N  |------+------+------+------+------+--------|
 * |  Shift  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  ?   |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | CTRL  |   K  |   N  |   O  |  Alt |                                       |  F1  |  F2  |  F3  |  F4  |  F5  |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |GameTG|      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |Space | Map  |------|       |------| Enter|      |
 *                                 |      |      | Esc  |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SATISFACTORY] = LAYOUT_ergodox_pretty(
  // left hand
  KC_LGUI,         KC_1,        KC_2,          KC_3,        KC_4,    KC_5,    KC_TRNS,                  KC_K,     KC_6,    KC_7,    KC_8,    KC_9,     KC_0,      KC_BSPC,
  KC_TAB,          KC_Q,        KC_W,          KC_E,        KC_R,    KC_T,    KC_J,                     KC_L,     KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,      KC_F12,
  KC_ESC,          KC_A,        KC_S,          KC_D,        KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,   KC_TRNS,
  KC_LSFT,         KC_Z,        KC_X,          KC_C,        KC_V,    KC_B,    KC_I,                     KC_N,     KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,   KC_TRNS,
  KC_LCTL,         KC_K,        KC_N,          KC_O,        KC_LALT,                                                       KC_F1,   KC_F2,   KC_F3,    KC_F4,     KC_F5,

                                               KC_TRNS, TG(SATISFACTORY),  KC_TRNS, KC_TRNS,
                                                                 KC_TRNS,  KC_TRNS,
                                                   KC_SPC, KC_M, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 1: Password Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |NTID U&P |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * | RESW    |      |      |      |      |      |      |           |      |      |      |      |      |  PG  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |E-num | Pin  |workp |homep |      |------|           |------|      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[PASS] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, NTID_JUST_P, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, NTID_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, POSTGRES, KC_TRNS,
  KC_TRNS, ENUMBER, PIN,     WORK_PW, HOME_PW, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),
};

