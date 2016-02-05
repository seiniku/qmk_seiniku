#include "seiniku.h"

/* This layout implements colemak in the firmware, so you don't have to
   set the OS configuration into colemak layout. Useful if you don't have
   a laptop with an internal keyboard, or if you use other peoples' computers
   a lot. */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
   *
   *  q    w    f    p    g       ||       j    l    u    y    ;
   *  a    r    s    t    d       ||       h    n    e    i    o
   *  z    x    c    v    b       ||       k    m    ,    .    /
   * esc tab meta ctrl shift bksp || space fn0  alt  -    '    enter
   *
   */
    
  /* 0: colemak */
  KEYMAP(KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, \
         KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, \
         KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, \
         KC_ESC, KC_TAB, KC_LGUI, KC_LCTL, KC_LSFT, KC_BSPC, KC_FN5,     \
         KC_FN0, KC_LALT, KC_MINS, KC_QUOT, KC_ENT),                     \
  /* 1: punctuation and numbers */
  FN_ARROW_LAYER, \
  /* 2: arrows and function keys */
  LAYER_TWO
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
  [1] = ACTION_LAYER_ON(2, 1),  // switch to layer 2
  [2] = ACTION_LAYER_OFF(2, 1),  // switch back to layer 0
  [3] = ACTION_FUNCTION(BOOTLOADER),
  [4] = ACTION_MODS_KEY(MOD_LCTL | MOD_LALT, KC_DEL),
  [5] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_SPC)
};

/*void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}
*/
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
