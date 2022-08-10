// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum ferris_layers {
  _QWERTY,
  _LOWER, 
  _RAISE 
};  
enum ferris_tap_dances {
  TD_Q_ESC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( /* QWERTY */
    TD(TD_Q_ESC),    KC_W,    KC_E,    KC_R, KC_T,                KC_Y,    KC_U,  KC_I,    KC_O,   KC_P,
    KC_A, KC_S, KC_D, KC_F, LCTL_T(KC_G),                 LCTL_T(KC_H),     KC_J,  KC_K,KC_L, LALT_T(KC_SCLN),
    KC_Z, KC_X, KC_C, KC_V, KC_B,     KC_N,                       KC_M,  KC_COMM, KC_DOT, KC_ENT, 
                           GUI_T(KC_TAB), KC_LSFT,         LT(2, KC_SPC), LT(1,KC_BSPC)
  ),

  [_RAISE] = LAYOUT(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                 KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_ESC, KC_HOME, KC_PGDN, KC_PGUP, LCTL_T(KC_END),          LCTL_T(KC_LEFT), KC_DOWN, KC_UP,   KC_RGHT, LALT_T(KC_QUOT),
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
                                    _______, _______,                          _______, _______  
  ),

  [_LOWER] = LAYOUT( 
     KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR,  KC_F11,   KC_F12,
   KC_EQL, KC_PLUS, KC_MINS, KC_LPRN, KC_RPRN,           LCTL_T(KC_LBRC), KC_RBRC,  KC_LCBR, KC_RCBR,KC_UNDERSCORE,
    _______, _______, _______, KC_VOLU, KC_VOLD,                        KC_PIPE, KC_BSLASH, KC_GRAVE, KC_QUES , KC_SLASH,
                                    _______, _______,                       _______, _______
  )
};
// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Q, twice for ESC
    [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC)
};

