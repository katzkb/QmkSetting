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

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

enum custom_keycodes {
  M_CMDR = SAFE_RANGE,
  M_CMDT,
  M_CMDY,
  M_CMDU,
  M_CMD_FW,
  M_CMD_BK,
  M_SCLSH,
  M_CTRV,
  M_ALTV,
  QWERTY,
  LOWER,
  RAISE
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

#define KC_ KC_TRNS
#define KC_RST RESET
#define KC_L_SPC LT(_LOWER, KC_SPC) // lower
#define KC_R_ENT LT(_RAISE, KC_ENT) // raise
#define KC_G_JA LGUI_T(KC_LANG1) // cmd or win
#define KC_G_EN LGUI_T(KC_LANG2) // cmd or win
#define KC_C_BS LCTL_T(KC_BSPC) // ctrl
#define KC_A_DEL ALT_T(KC_DEL) // alt
#define KC_S_JA RSFT_T(KC_LANG1)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case M_CMDR:
        SEND_STRING(SS_LGUI(SS_TAP(X_R)));
        break;
      case M_CMDT:
        SEND_STRING(SS_LGUI(SS_TAP(X_T)));
        break;
      case M_CMDY:
        SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_T))));
        break;
      case M_CMDU:
        SEND_STRING(SS_LGUI(SS_TAP(X_W)));
        break;
      case M_CMD_FW:
        SEND_STRING(SS_LGUI(SS_TAP(X_RIGHT)));
        break;
      case M_CMD_BK:
        SEND_STRING(SS_LGUI(SS_TAP(X_LEFT)));
        break;
      case M_SCLSH:
        SEND_STRING(SS_LCTRL(SS_LALT(SS_LSFT(SS_TAP(X_4)))));
        break;
    }
  }
  switch(keycode) {
    case M_CTRV:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL(SS_DOWN(X_V)));
        break;
      } else {
        SEND_STRING(SS_LCTRL(SS_UP(X_V)));
        break;
      }
    case M_ALTV:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_DOWN(X_V)));
        break;
      } else {
        SEND_STRING(SS_LALT(SS_UP(X_V)));
        break;
      }
  }
  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( \
  //,-----------------------------------------------.                 ,-----------------------------------------------.
      KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,KC_BSPC,\
  //|-------+-------+-------+-------+-------+-------|                 |-------+-------+-------+-------+-------+-------|
     KC_LCTL,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                     KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN,KC_QUOT,\
  //|-------+-------+-------+-------+-------+-------|                 |-------+-------+-------+-------+-------+-------|
     KC_LSFT,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                     KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH, KC_ENT,\
  //|-------+-------+-------+-------+-------+-------+------|  |-------+-------+-------+-------+-------+-------+-------|
                             KC_LGUI,KC_LALT,  LT(2,KC_SPC),   LT(1,KC_SPC),KC_S_JA, TG(3) \
                                  //`----------------------'  `-----------------------'
  ),
  [1] = LAYOUT( \
  //,-----------------------------------------------.                 ,-----------------------------------------------.
      KC_TAB,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,KC_BSPC,\
  //|-------+-------+-------+-------+-------+-------|                 |-------+-------+-------+-------+-------+-------|
     KC_LCTL,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,                    KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11,\
  //|- ------+-------+-------+-------+-------+-------|                 |-------+-------+-------+-------+-------+-------|
     KC_LSFT,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,\
  //|-------+-------+-------+-------+-------+-------|                 |-------+-------+-------+-------+-------+-------|
                             KC_LGUI, KC_LALT, LT(2,KC_SPC),   LT(1,KC_SPC),KC_S_JA, TG(3) \
                                  //`----------------------'  `-----------------------'
  ),
  [2] = LAYOUT( \
  //,-----------------------------------------------.                 ,-----------------------------------------------.
    KC_GRAVE,KC_EXLM,  KC_AT,KC_HASH, KC_DLR,KC_PERC,                  KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_BSPC,\
  //|-------+-------+-------+-------+-------+-------|                 |-------+-------+-------+-------+-------+-------|
     KC_LCTL,  KC_NO,  KC_NO,  KC_NO,  KC_NO,KC_LBRC,                  KC_RBRC,KC_MINS,KC_PLUS,KC_PIPE,  KC_NO,  KC_NO,\
  //|-------+-------+-------+-------+-------+-------|                 |-------+-------+-------+-------+-------+-------|
     KC_LSFT, KC_GRV,  KC_NO,  KC_NO,  KC_NO,KC_LCBR,                  KC_RCBR,KC_UNDS, KC_EQL,KC_BSLS,  KC_NO,  KC_NO,\
  //|-------+-------+-------+-------+-------+-------|                 |-------+-------+-------+-------+-------+-------|
                             KC_LGUI, KC_LALT, LT(2,KC_SPC),   LT(1,KC_SPC),KC_S_JA, TG(3) \
                                  //`----------------------'  `-----------------------'
  ),
  [3] = LAYOUT( \
  //,-----------------------------------------------.                 ,-----------------------------------------------.
     RGB_TOG,KC_BTN1,RGB_SAI,KC_MS_U, M_CMDR, M_CMDT,                   M_CMDY, M_CMDU,RGB_SAI,RGB_TOG,RGB_MOD,M_SCLSH,\
  //|-------+-------+-------+-------+-------+-------|                 |-------+-------+-------+-------+-------+-------|
     KC_LCTL,RGB_HUI,KC_MS_L,KC_MS_D,KC_MS_R,KC_WH_D,                 M_CMD_BK,KC_BTN1,KC_BTN2,M_CMD_FW, KC_UP,  KC_NO,\
  //|-------+-------+-------+-------+-------+-------|                 |-------+-------+-------+-------+-------+-------|
     KC_LSFT,RGB_HUD,KC_WH_R,  KC_NO,KC_WH_L,KC_WH_U,                  RGB_VAI,RGB_VAD,RGB_SAD,KC_LEFT,KC_DOWN,KC_RGHT,\
  //|-------+-------+-------+-------+-------+-------|                 |-------+-------+-------+-------+-------+-------|
                                  KC_LGUI, KC_LALT, KC_ACL1,   KC_ACL0,KC_S_JA, KC_TRNS \
                                  //`----------------------'  `-----------------------'
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
