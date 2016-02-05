// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "atreus.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _CO 0
#define _RS 1
#define _LW 2
// dual use ctrl/esc
// dual use alt/spc
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_CO] = {

    /* Colemak
     *      Q   W   F   P   G     |     J   L   U   Y   :
     *      A   R   S   T   D     |     H   N   E   I   O
     *      Z   X   C   V   B     |     K   M   <   >   ?
     * SFT/ESC TAB SUP SFT BSPC   | SP/SFT _RS   -   '  SFT/ENT  
     *                       CTRL   ALT
     *
     */

  {KC_Q,        KC_W,   KC_F,    KC_P,    KC_G,    KC_TRNS  KC_J,   KC_L,    KC_U,    KC_Y,    KC_SCLN},
  {KC_A,        KC_R,   KC_S,    KC_T,    KC_D,    KC_TRNS, KC_H,   KC_N,    KC_E,    KC_I,    KC_O },
  {SFT_T(KC_Z), KC_X,   KC_C,    KC_V,    KC_B,    KC_LALT, KC_K,   KC_M,    KC_COMM, KC_DOT,  SFT_T(KC_SLSH) },
  {KC_ESC,      KC_TAB, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, LT(_RS, KC_SPC), MO(_LW), KC_MINS, KC_QUOT, KC_ENT }
   
},


[_RS] = {
  
    /*  > RAISE <
     *  !   @   {   }   |     |    PGU  8   8   9   *
     *  #   $   (   )   `     |    PGD  4   5   6   +
     *  %   ^   [   ]   ~     |     &   1   2   3   \
     * _LW INS SUP SFT BSPC   | SP/SFT L0   -   0   =  
     *                   CTRL   ALT
    */

  {KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS, KC_PGUP, KC_7,    KC_8,   KC_9, KC_ASTR},
  {KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  KC_TRNS, KC_PGDN, KC_4,    KC_5,   KC_6, KC_PLUS},
  {KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_LALT, KC_AMPR, KC_1,    KC_2,   KC_3, KC_BSLS},
  {TG(_LW), KC_INS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DOT, KC_0, KC_EQL}
},


[_LW] = { 
    
    /*  > LOWER <
     *  INS HOME UP END PGU   |    UP   F7   F8   F9   F10
     *  DEL LFT DWN RHT DWN   |    DWN  F4   F5   F6   F11
     *   %   ^   [   ]   ~    |     &   F1   F2   F3   F12
     * ESC TAB SUP SFT BSPC   | SP/SFT  L0   .    0   RESET  
     *                   CTRL   ALT
     */

  {KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_TRNS, KC_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10},
  {KC_DELT, KC_LEFT, KC_DOWN, KC_RGHT, KC_DOWN, KC_TRNS, KC_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LALT, KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F12},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET}
}};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_SPC)
};

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
