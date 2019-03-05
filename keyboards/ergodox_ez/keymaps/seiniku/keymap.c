#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  RGB_SLD,

};
/*
[1] = LAYOUT_ergodox(_______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,

                       _______,_______,_______,
                       _______,_______,_______,

                       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,

                       _______,_______,_______,
                       _______,_______,_______),
 */
// 7 7 6 7 5 3 3 7 7 6 7 5 3 3
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox(KC_GESC,KC_1,KC_2,KC_3,KC_4,KC_5,KC_LEFT,
                      KC_TAB,KC_Q,KC_W,KC_F,KC_P,KC_G,TG(2),
                      LCTL_T(KC_GESC),KC_A,KC_R,KC_S,KC_T,KC_D,
                      KC_LSPO,SFT_T(KC_Z),KC_X,KC_C,KC_V,KC_B,KC_HYPR,
                      LT(1,KC_GRAVE),KC_LBRACKET,KC_TAB,KC_LEFT,KC_RIGHT,

                      LALT_T(KC_APPLICATION),KC_LGUI,KC_HOME,
                      KC_BSPACE,LCTL_T(KC_ESCAPE),KC_END,

                      KC_RIGHT,KC_6,KC_7,KC_8,KC_9,KC_0,KC_EQUAL,
                      TG(1),KC_J,KC_L,KC_U,KC_Y,KC_SCOLON,KC_BSLASH,
                      KC_H,KC_N,KC_E,KC_I,KC_O,LGUI_T(KC_QUOTE),
                      KC_MEH,KC_K,KC_M,KC_COMMA,KC_DOT,SFT_T(KC_SLSH),KC_RSPC,
                      MO(2),KC_MINUS,KC_QUOTE,KC_RBRACKET,MO(1),

                      LCTL(LALT(KC_DEL)),LCTL_T(KC_ESCAPE),KC_PGUP,
                      KC_PGDOWN,RALT_T(KC_ENTER),KC_SPACE),

  [1] = LAYOUT_ergodox(KC_ESCAPE,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,_______,
                       _______,KC_EXLM,KC_AT,KC_LCBR,KC_RCBR,KC_PIPE,_______,
                       _______,KC_HASH,KC_DLR,KC_LPRN,KC_RPRN,KC_GRAVE,
                       _______,KC_PERC,KC_CIRC,KC_LBRACKET,KC_RBRACKET,KC_TILD,_______,
                       _______,_______,_______,_______,_______,


                       _______,_______,_______,
                       _______,_______,_______,

                       _______,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,
                       _______,KC_UP,KC_7,KC_8,KC_9,KC_ASTR,KC_F12,
                       KC_DOWN,KC_4,KC_5,KC_6,KC_PLUS,_______,
                       _______,KC_AMPR,KC_1,KC_2,KC_3,KC_BSLASH,KC_MINUS,
                       KC_0,KC_DOT,KC_0,KC_EQUAL,KC_EQL,

                       _______,_______,_______,
                       _______,_______,_______),


  [2] = LAYOUT_ergodox(_______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,

                       RGB_TOG,RGB_MODE_FORWARD,RGB_MODE_REVERSE,
                       RGB_VAD,RGB_VAI,_______,

                       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,_______,_______,
                       _______,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,_______,
                       _______,_______,_______,_______,_______,_______,_______,
                       _______,_______,_______,_______,_______,

                       RGB_TOG,RGB_SLD,_______,
                       _______,RGB_HUD,RGB_HUI),

};

bool suspended = false;
rgb_config_t rgb_matrix_config;

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { //right hand
            {32,255,234}, {32,255,234}, {32,255,234}, {32,255,234}, {32,255,234},
            {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255},
            {146,224,255}, {0,204,255}, {0,204,255}, {0,204,255}, {0,204,255},
            {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            //left hand
            {32,255,234}, {32,255,234}, {32,255,234}, {32,255,234}, {32,255,234},
            {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255},
            {146,224,255}, {0,204,255}, {0,204,255}, {0,204,255}, {0,204,255},
            {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255}, {146,224,255},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [1] = { //right hand
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {169,120,255}, {169,120,255}, {169,120,255}, {0,0,0},
            {0,0,0}, {169,120,255}, {169,120,255}, {169,120,255}, {0,0,0},
            {0,0,0}, {169,120,255}, {169,120,255}, {169,120,255}, {0,0,0},
            {0,0,0}, {0,0,0}, {169,120,255}, {0,0,0},
            //left hand
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [2] = { //right hand
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {169,120,255}, {169,120,255}, {169,120,255}, {169,120,255},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            //left hand
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_leds_color( int layer) {
  rgb_matrix_mode_noeeprom(1);
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    uint8_t val = pgm_read_byte(&ledmap[layer][i][2]);
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = val == 0 ? 0 : rgb_matrix_config.val
    };
    RGB rgb = hsv_to_rgb( hsv );
    rgb_matrix_set_color( i, rgb.r, rgb.g, rgb.b );
  }
}

void rgb_matrix_indicators_user(void) {
  if(suspended == false) {
    uint8_t layer = biton32(layer_state);
    switch (layer) {
      case 0:
        rgb_matrix_config.raw = eeprom_read_dword(EECONFIG_RGB_MATRIX);
        rgb_matrix_mode_noeeprom(rgb_matrix_config.mode);
        if(rgb_matrix_config.mode != 1) {
          rgb_matrix_sethsv_noeeprom(rgb_matrix_config.hue, rgb_matrix_config.sat, rgb_matrix_config.val);
        }
        break;
      case 1:
        set_leds_color(1);
        break;
      case 2:
        set_leds_color(2);
        break;
    }
  }
}
const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 1:
        ergodox_right_led_1_on();
        break;
      case 2:
        ergodox_right_led_2_on();
        break;
      case 3:
        ergodox_right_led_3_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }
    return state;

};
