// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum planck_layers {
  _QWERTY,
  _WORKMANP,
  _DVORAK,
  _LOWER,
  _RAISE,
  _MOUSECURSOR,
  _PLOVER,
  _ADJUST,
  _GUI
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  WORKMANP,
  DVORAK,
  PLOVER,
  LOWER,
  RAISE,
  BACKLIT,
  EXT_PLV,
  GUI
};

enum {
  POSOCO = 0,
  PCSCCC = 0
};

//Tap Dance Definition
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Parenthetic Open, twice for SquareP Open, thrice for CurlyP
  //Open
  [POSOCO]  = ACTION_TAP_DANCE_DOUBLE(KC_LSPO, KC_LBRC),
  //Tap once for Parenthetic Close, twice for SquareP Close, thrice for CurlyP
  //Close
  [PCSCCC]  = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_ESC)
  // Other declarations would go here, separated by commas, if you have them
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Custom Macros
#define LT_MC(kc)   LT(_MOUSECURSOR, kc)        // L-ayer T-ap M-ouse C-ursor
#define LT_V(kc)    LT(_MOUSECURSOR, kc)        // L-ayer T-ap M-ouse C-ursor

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Ctl/CL|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |  \   |  GUI | Alt  |Lower |RShift| Space|Raise | Home | PgUp | PgDn | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {MT(MOD_LCTL,KC_CAPS),  KC_A,    KC_S, LT_MC(KC_D),KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSPO, KC_Z,    KC_X,    KC_C, LT_V(KC_V), KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {KC_ESC , KC_NUBS, OSL(_GUI), KC_LALT,   LOWER,   KC_RSPC, KC_SPC,  RAISE,   KC_HOME, KC_PGUP, KC_PGDN,   KC_END }
},

/* Workman-P
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   D  |   R  |   B  |   J  |   F  |   U  |   P  |   ;  |   '  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Ctl/CL|   A  |   S  |   H  |   T  |   G  |   Y  |   N  |   E  |   O  |   I  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   M  |   C  |   V  |   K  |   L  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |  \   |  GUI | Alt  |Lower |RShift| Space|Raise | Home | PgUp | PgDn | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_WORKMANP] = {
  {KC_TAB,  KC_Q,    KC_D,    KC_R,    KC_B,    KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, KC_QUOT, KC_BSPC},
  {MT(MOD_LCTL,KC_CAPS),  KC_A,    KC_S, LT_MC(KC_H),KC_T,    KC_G,    KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    KC_BSLS},
  {KC_LSPO, KC_Z,    KC_X,    KC_M, LT_V(KC_C), KC_V,    KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {KC_ESC , KC_NUBS, OSL(_GUI), KC_LALT,   LOWER,   KC_RSPC, KC_SPC,  RAISE,   KC_HOME, KC_PGUP, KC_PGDN,   KC_END }
},

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Ctl/CL|   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |LShift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |  \   |  GUI | Alt  |Lower |RShift| Space|Raise | Home | PgUp | PgDn | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = {
  {KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC},
  {MT(MOD_LCTL,KC_CAPS),  KC_A,    KC_O, LT_MC(KC_E),KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH},
  {KC_LSPO, KC_SCLN, KC_Q,    KC_J, LT_V(KC_K), KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT },
  {KC_ESC , KC_NUBS, OSL(_GUI), KC_LALT,   LOWER,   KC_RSPC, KC_SPC,  RAISE,   KC_HOME, KC_PGUP, KC_PGDN,   KC_END }
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |   {  |   7  |   8  |   9  |   }  |   -  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |   [  |   6  |   5  |   4  |   ]  |   =  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |   (  |   1  |   2  |   3  |   )  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Delete|      |      |      |      |      |      |      |   0  |   .  |   /  |   *  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {_______, _______, _______, _______, _______, _______, KC_LCBR, KC_7,    KC_8,    KC_9,    KC_RCBR, KC_MINS},
  {_______, _______, _______, _______, _______, _______, KC_LBRC, KC_4,    KC_5,    KC_6,    KC_RBRC, KC_EQL },
  {_______, _______, _______, _______, _______, _______, KC_LPRN, KC_1,    KC_2,    KC_3,    KC_RPRN, KC_ENT },
  {KC_DEL , _______, _______, _______, _______, _______, _______, _______, KC_0,    KC_DOT,  KC_SLSH, KC_ASTR}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |      |      |      |      |      |
 * |------+------+------+------+------|-------------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | Left | Down |  Up  |Right |      |  #   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  `   |  \   |  |   |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, _______, _______, _______, _______},
  {KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, KC_NUHS},
  {_______, KC_GRV,  KC_NUBS, KC_PIPE, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Mouse Layer
 * ,-----------------------------------------------------------------------------------.
 * |      |      |ACCL0 |      |      |      |      |WHL_L |  Up  |WHL_R | BTN2 |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |ACCL2 | BTN2 |      | BTN1 |ACCL1 |WHL_Up| Left | Down |Right | BTN4 | BTN5 |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      | BTN3 |      |WHL_Dn| BTN1 |      |      | BTN3 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_MOUSECURSOR] = {
  {_______, _______, KC_ACL0, _______, _______, _______, _______, KC_WH_L, KC_MS_U, KC_WH_R, KC_BTN2, _______},
  {_______, KC_ACL2, KC_BTN2, _______, KC_BTN1, KC_ACL1, KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN4, KC_BTN5},
  {_______, _______, _______, _______, KC_BTN3, _______, KC_WH_D, KC_BTN1, _______, _______, KC_BTN3, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |TogOut|   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_PLOVER] = {
  {KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   },
  {XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC},
  {XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL},
  {_______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY, WORKMANP,  DVORAK,  PLOVER, _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* GUI
 * ,-----------------------------------------------------------------------------------.
 * |      |GUI+1 |GUI+2 |GUI+3 |GUI+4 |GUI+5 |GUI+6 |GUI+7 |GUI+8 |GUI+9 |GUI+0 |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  GUI |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_GUI] = {
  {_______, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), LGUI(KC_0),    _______},
  {_______, _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______},
  {_______, _______,   _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______ },
  {_______, _______,   KC_TRNS,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,   _______}
}


};

#ifdef AUDIO_ENABLE

float tone_startup[][2]    = SONG(STARTUP_SOUND);
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_workmanp[][2]   = SONG(COLEMAK_SOUND);
float tone_plover[][2]     = SONG(PLOVER_SOUND);
float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
#endif


void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case WORKMANP:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_workmanp, false, 0);
        #endif
        persistant_default_layer_set(1UL<<_WORKMANP);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_dvorak, false, 0);
        #endif
        persistant_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_NOTE_ARRAY(tone_plover, false, 0);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_plover_gb, false, 0);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
  }
  return true;
}

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}

#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
    PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user()
{
    PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_NOTE_ARRAY(music_scale, false, 0);
}

#endif
