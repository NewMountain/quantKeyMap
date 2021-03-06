#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define POKR 1 // Pok3r layer FTW
#define MOUZ 2 // Mouse Layer
#define HAKR 3 // All the programming jazz
#define EXZL 4 // Make those spreadsheets cry

#define ASSIGN 10
#define JS_FUNC 11
#define F_PIPE 12
#define B_PIPE 13
#define JS_COMMENT 14
#define EQUAL_TO 15
#define NOT_EQUAL 16
#define APPLY_TO 17
#define FMAP 18
#define APPLICATIVE 19
#define HAS_TYPE 20
#define BIND 21
#define DOC_STRING 22
#define TRIPLE_ZERO 23



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: BASE
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |  1/! |  2/@ |  3/# |  4/$ |  5/% |      |           |CtAlDe|  6/^ |  7/& |  8/* |  9/( |  0/) | BSpace |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  POKR  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  | ;/:  |'/"/MOUZ|
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  | //?  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl |  WIN |      | Alt  | HAKR |                                       |EXZLTg|  ??  |      |      |RCtrl |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 |BSpace| Del  |------|       |------|  Enter |Space |
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,    KC_1,         KC_2,     KC_3,   KC_4,   KC_5,   KC_TRNS,
        KC_TAB,    KC_Q,         KC_W,     KC_E,   KC_R,   KC_T,   KC_TRNS,
        MO(POKR),  KC_A,         KC_S,     KC_D,   KC_F,   KC_G,
        KC_LSFT,   KC_Z,         KC_X,     KC_C,   KC_V,   KC_B,   KC_TRNS,
        KC_LCTL,   KC_LGUI,      KC_TRNS,  KC_LALT,OSL(HAKR),
                                                    KC_TRNS,  KC_TRNS,
                                                              KC_HOME,
                                               KC_BSPC,KC_DELETE,KC_END,
        // right hand
  LALT(LCTL(KC_DEL)),     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_BSPC,
             KC_TRNS,     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_BSLS,
                          KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,LT(MOUZ, KC_QUOT),
             KC_TRNS,     KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          KC_RSFT,
                              TG(EXZL),   KC_TRNS,KC_TRNS,KC_TRNS,          KC_RCTL,
             KC_TRNS,        KC_TRNS,
             KC_PGUP,
             KC_PGDN,KC_ENT, KC_SPC
    ),
/* Keymap 1: POKR LAYER
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |  Del   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | VolUp|      |      |      |           |      |      | PgUp | ArrU | PgDn |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      | VolDn|      |      |------|           |------|      | ArrL | ArrD | ArrR |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |      |      |      |      |      |      |           |      |      | Home | End  |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------| Enter|      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// POKR
[POKR] = KEYMAP(
       // left hand
       KC_TRNS,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_VOLU,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_VOLD,KC_TRNS,KC_TRNS,
       KC_LSFT,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_LCTL,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_F7,   KC_F8,    KC_F9, KC_F10,  KC_F11,  KC_F12, KC_DEL,
       KC_TRNS, KC_TRNS,KC_PGUP,  KC_UP, KC_PGDN, KC_TRNS, KC_TRNS,
                KC_TRNS,KC_LEFT,KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,KC_HOME, KC_END, KC_TRNS, KC_TRNS, KC_TRNS,
                        KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_ENT, KC_TRNS
),
/* Keymap 2: MOUZ - this will likely get some more updates over time
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |MsFast|      | MsUp |      |      |      |           |      |      |      |MsWhUp|      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |MsMedi|MsLeft|MsDown|MsRght|      |------|           |------|      |      |MsWhDn|      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |MsSlow|      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------| Lclk | RClk |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MOUZ
[MOUZ] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_ACL2, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_ACL1, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_ACL0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_WH_U, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_WH_D, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_BTN1, KC_BTN2
),
/* Keymap 3: HAKR
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |    %   |   !  |  <|  |   {  |   }  |  ~   |      |           |  ==  |   &  |  +   |   <  |  *   |  <*> |   >>=  |
 * |--------+------+------+------+------+------|  #   |           |      |------+------+------+------+------+--------|
 * |    ^   |  <-  |  |>  |   (  |   )  |  .   |------|           |------|   :  |  _   |   >  |  <$> |   =  |  """   |
 * |--------+------+------+------+------+------|  //  |           |  !=  |------+------+------+------+------+--------|
 * |    ;   |  =>  |   $  |   [  |   ]  |  `   |      |           |      |   |  |  -   |  ->  |  /   |  ::  |   @    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
//
[HAKR] = KEYMAP(
       KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,
       KC_PERC,    KC_EXLM,M(B_PIPE), KC_LCBR, KC_RCBR, KC_TILD,      KC_HASH,
       KC_CIRC,  M(ASSIGN),M(F_PIPE), KC_LPRN, KC_RPRN,  KC_DOT,
       KC_SCLN, M(JS_FUNC),   KC_DLR, KC_LBRC, KC_RBRC,  KC_GRV,M(JS_COMMENT),
       KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,       KC_TRNS,      KC_TRNS,
   M(EQUAL_TO),  KC_AMPR, KC_PPLS,    KC_LABK, KC_PAST,M(APPLICATIVE),      M(BIND),
                 KC_COLN, KC_UNDS,    KC_RABK,  M(FMAP),       KC_EQL,M(DOC_STRING),
  M(NOT_EQUAL),  KC_PIPE, KC_PMNS,M(APPLY_TO), KC_PSLS,   M(HAS_TYPE),        KC_AT,
                          KC_TRNS,    KC_TRNS, KC_TRNS,       KC_TRNS,      KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 4: EXZL
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |   Del  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |  7   |  8   |  9   |      |      |           |      |      |  +   | ArrU |  *   |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |  4   |  5   |  6   |  0   |------|           |------|      | ArrL | ArrD | ArrR |   =  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |      |  1   |  2   |  3   | 000  |      |           |      |      |  -   |      |  /   |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      | Enter|      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
//
[EXZL] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_DEL,
       KC_TRNS, KC_TRNS,    KC_7,    KC_8,    KC_9,       KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,    KC_4,    KC_5,    KC_6,          KC_0,
       KC_LSFT, KC_TRNS,    KC_1,    KC_2,    KC_3,M(TRIPLE_ZERO), KC_TRNS,
       KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_PPLS,   KC_UP, KC_PAST, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT,  KC_EQL, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_PMNS, KC_TRNS, KC_PSLS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_ENT, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
    case ASSIGN:
      if(record->event.pressed){
        return MACRO( D(LSHIFT), T(LABK), U(LSHIFT), T(PMNS), END);
      }
      break;
    case JS_FUNC:
        if(record->event.pressed){
          return MACRO( T(EQL), D(LSHIFT), T(RABK), U(LSHIFT), END);
        }
        break;
    case B_PIPE:
        if(record->event.pressed){
          return MACRO( D(LSHIFT), T(LABK), T(PIPE), U(LSHIFT), END);
        }
        break;
    case F_PIPE:
        if(record->event.pressed){
          return MACRO( D(LSHIFT), T(PIPE), T(RABK), U(LSHIFT), END);
        }
        break;
    case JS_COMMENT:
        if(record->event.pressed){
          return MACRO( T(SLSH), T(SLSH), END);
        }
        break;
    case EQUAL_TO:
        if(record->event.pressed){
          return MACRO( T(EQL), T(EQL), END);
        }
        break;
    case NOT_EQUAL:
        if(record->event.pressed){
          return MACRO( D(LSHIFT), T(EXLM), U(LSHIFT), T(EQL), END);
        }
        break;
    case APPLY_TO:
        if(record->event.pressed){
          return MACRO( T(PMNS), D(LSHIFT), T(RABK), U(LSHIFT), END);
        }
        break;
    case FMAP:
        if(record->event.pressed){
          return MACRO( D(LSHIFT), T(LABK), T(DLR), T(RABK), U(LSHIFT), END);
        }
        break;
    case APPLICATIVE:
        if(record->event.pressed){
          return MACRO( D(LSHIFT), T(LABK), T(ASTR), T(RABK), U(LSHIFT), END);
        }
        break;
    case HAS_TYPE:
        if(record->event.pressed){
          return MACRO( D(LSHIFT), T(COLN), T(COLN), U(LSHIFT), END);
        }
        break;
    case BIND:
        if(record->event.pressed){
          return MACRO( D(LSHIFT), T(RABK), T(RABK), U(LSHIFT), T(EQL), END);
        }
        break;
    case DOC_STRING:
        if(record->event.pressed){
          return MACRO( D(LSHIFT), T(QUOT), T(QUOT), T(QUOT), U(LSHIFT), END);
        }
        break;
    case TRIPLE_ZERO:
        if(record->event.pressed){
          return MACRO( T(0), T(0), T(0), END);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 0:
            ergodox_right_led_3_on();
            break;
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 4:
            //No light
            break;
        default:
            // none
            break;
    }

};
