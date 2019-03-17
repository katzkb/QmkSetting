#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern keymap_config_t keymap_config;

extern uint8_t is_master;

enum macro_keycodes {
  KC_M_PU,
//  KC_M_PN,
//  KC_M_PG,
//  KC_M_PY,
//  KC_M_PL,
//  KC_M_PP,
};

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
     KC_TAB,  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,                   KC_Y,  KC_U,  KC_I,  KC_O,  KC_P, KC_BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    KC_LCTL,  KC_A,  KC_S,  KC_D,  KC_F,  KC_G,                   KC_H,  KC_J,  KC_K,  KC_L,KC_SCLN,KC_QUOT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    KC_LSFT,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,                   KC_N,  KC_M,KC_COMM,KC_DOT,KC_SLSH,KC_ENT,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                        KC_LGUI, KC_LALT, LT(2,KC_SPC), LT(1,KC_SPC), KC_RALT, TG(3) \
                              //`--------------------'  `--------------------'
  ),
  [1] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
     KC_TAB,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,                   KC_6,  KC_7,  KC_8,  KC_9,  KC_0,KC_BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    KC_LCTL, KC_NO, KC_NO,KC_TILD,KC_PIPE,KC_LCBR,             KC_RCBR,KC_MINS,KC_PLUS,KC_NO,KC_NO, KC_NO,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    KC_LSFT, KC_NO, KC_NO,KC_GRV,KC_BSLS,KC_LBRC,              KC_RBRC,KC_UNDS,KC_EQL,KC_NO, KC_NO, KC_NO,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                        KC_LGUI, KC_LALT, LT(2,KC_SPC), LT(1,KC_SPC), KC_RALT, TG(3) \
                              //`--------------------'  `--------------------'
  ),
  [2] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
    KC_TAB,KC_EXLM, KC_AT,KC_HASH,KC_DLR,KC_PERC,              KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    KC_LCTL, KC_NO, KC_NO,KC_TILD,KC_PIPE,KC_LCBR,             KC_RCBR,KC_MINS,KC_PLUS,KC_NO,KC_NO, KC_NO,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO,KC_LBRC,               KC_RBRC,KC_UNDS,KC_EQL,KC_NO, KC_NO, KC_NO,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                        KC_LGUI, KC_LALT, LT(2,KC_SPC), LT(1,KC_SPC), KC_RALT, TG(3) \
                              //`--------------------'  `--------------------'
  ),
  [3] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
    RGB_TOG, KC_NO,RGB_SAI,KC_MS_U,KC_NO,KC_NO,                  KC_NO, KC_NO, KC_NO,RGB_TOG,RGB_MOD,KC_BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    KC_LCTL,RGB_HUI,KC_MS_L,KC_MS_D,KC_MS_R,KC_PGUP,           RGB_VAI,KC_BTN1,KC_BTN2,KC_NO,KC_UP, KC_NO,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    KC_LSFT,RGB_HUD,RGB_SAD,KC_NO,KC_NO,KC_PGDN,               RGB_VAD, KC_NO, KC_NO,KC_LEFT,KC_DOWN,KC_RGHT,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                        KC_LGUI, KC_LALT, LT(2,KC_SPC), LT(1,KC_SPC), KC_RALT, KC_TRNS \
                              //`--------------------'  `--------------------'
  )
};

/*
 * Macro definition
 */
/*
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  return MACRO_NONE;
}
*/
