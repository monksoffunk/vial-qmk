#define LCTLTAB     MT(MOD_LCTL, KC_TAB)
#define LCTLESC     MT(MOD_LCTL, KC_ESC)
#define LOWELNG2    LT(_LOWER, KC_LNG2)
#define RAISLNG1    LT(_RAISE, KC_LNG1)
#define EXTLEFT     LT(_EXTRA, KC_LEFT)
#define ADJUST      MO(_ADJUST)

/* Default Layer
 * ,-----------------------------------------------------------------------.
 * | Esc |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  | BS  |
 * |-----------------------------------------------------------------------|
 * | Tab |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |
 * |-----------------------------------------------------------------------|
 * |LSft |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  | .   |  /  | Ent |
 * |-----------------------------------------------------------------------|
 * |LCtl |LAlt | Adj |LGui |Lower| Spc | Bs  |Raise|Left |Down |  Up |Right|
 * `-----------------------------------------------------------------------'
 */

#define __________40_ORTHO_DEFAULT_1__________ KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC
#define __________40_ORTHO_DEFAULT_2__________ LCTLTAB, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT
#define __________40_ORTHO_DEFAULT_3__________ KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT
#define __________40_ORTHO_DEFAULT_4__________ KC_LCTL, ADJUST,  KC_LALT, KC_LGUI, LOWELNG2,KC_SPC,  KC_BSPC, RAISLNG1,EXTLEFT, KC_DOWN, KC_UP,   KC_RGHT

/* Lower Layer fn0
 * ,-----------------------------------------------------------------------.
 * |  ~  |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  (  |  )  |     |
 * |-----------------------------------------------------------------------|
 * |     |     |     |     |     |     |     |  _  |  +  |  {  |  }  |Pipe |
 * |-----------------------------------------------------------------------|
 * |     |     |     |     |     |     |     |  ;  |  '  |     |     |     |
 * |-----------------------------------------------------------------------|
 * |     |     |     |     |     |     |     |     |     |     |     |     |
 * `-----------------------------------------------------------------------'
 */

#define ___________40_ORTHO_LOWER_1___________ KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______
#define ___________40_ORTHO_LOWER_2___________ _______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE
#define ___________40_ORTHO_LOWER_3___________ _______, _______, _______, _______, _______, _______, _______, KC_SCLN, KC_QUOT, _______, _______, _______
#define ___________40_ORTHO_LOWER_4___________ _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______

/* Raise Layer fn1
 * ,-----------------------------------------------------------------------.
 * |  `  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  | Del |
 * |-----------------------------------------------------------------------|
 * | F1  | F2  | F3  | F4  | F5  | F6  |     |  -  |  =  |  [  |  ]  |  \  |
 * |-----------------------------------------------------------------------|
 * | F7  | F8  | F9  | F10 | F11 | F12 |     |     |     |     |     |     |
 * |-----------------------------------------------------------------------|
 * |     |     |     |     |     |     |     |     |     |     |     |     |
 * `-----------------------------------------------------------------------'
 */

#define ___________40_ORTHO_RAISE_1___________ KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL
#define ___________40_ORTHO_RAISE_2___________ KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS
#define ___________40_ORTHO_RAISE_3___________ KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______, _______
#define ___________40_ORTHO_RAISE_4___________ _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______

/* Adjust Layer fn2
 * ,-----------------------------------------------------------------------.
 * | Mute| F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 |
 * |-----------------------------------------------------------------------|
 * | fn3 |RGBTO| VAI | SAI | MAC |RGBTO| HUI | WIN | SAI | VAI |     | F12 |
 * |-----------------------------------------------------------------------|
 * |Caps |RMOD | VAD | SAD |     |RMOD | HUD |     | SAD | VAD |     |     |
 * |-----------------------------------------------------------------------|
 * |SLEEP|     |     |     |     |     |     |     |     |     |     |     |
 * `-----------------------------------------------------------------------'
 */

#define __________40_ORTHO_ADJUST_1___________ KC_MUTE, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11
#define __________40_ORTHO_ADJUST_2___________ _EXTRA,  RGB_TOG, RGB_VAI, RGB_SAI, AG_NORM, RGB_TOG, RGB_HUI, AG_SWAP, RGB_SAI, RGB_VAI, _______, KC_F12
#define __________40_ORTHO_ADJUST_3___________ KC_CAPS, RGB_MOD, RGB_VAD, RGB_SAD, _______, RGB_MOD, RGB_HUD, _______, RGB_SAD, RGB_VAD, _______, _______
#define __________40_ORTHO_ADJUST_4___________ KC_SLEP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______

/* Extra Layer fn3
 * ,-----------------------------------------------------------------------.
 * |     |     |     |     |     |     |     |     |     | Up  |     |     |
 * |-----------------------------------------------------------------------|
 * |     |     |     |     |     |     |     |     |Left |Down |Right|     |
 * |-----------------------------------------------------------------------|
 * |     |BOOT |     |     |     |     |     |     |     |     |     |     |
 * |-----------------------------------------------------------------------|
 * |     |     |     |     |     |Enter|     |     |     |     |     |     |
 * `-----------------------------------------------------------------------'
 */

#define __________40_ORTHO_EXTRA_1___________ _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______
#define __________40_ORTHO_EXTRA_2___________ _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______
#define __________40_ORTHO_EXTRA_3___________ _______, QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
#define __________40_ORTHO_EXTRA_4___________ _______, _______, _______, _______, _______, KC_ENT,  _______, _______, _______, _______, _______, _______

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

#ifdef ENCODER_MAP_ENABLE
#    define ENCODER_CCW_CW_0 {ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_MNXT, KC_MPRV), ENCODER_CCW_CW(KC_MNXT, KC_MPRV), ENCODER_CCW_CW(KC_WBAK, KC_WFWD), ENCODER_CCW_CW(KC_WBAK, KC_WFWD), ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_SPC, KC_ENT), ENCODER_CCW_CW(KC_SPC, KC_ENT)}
#    define ENCODER_CCW_CW_1 {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MNXT, KC_MPRV), ENCODER_CCW_CW(KC_MNXT, KC_MPRV), ENCODER_CCW_CW(KC_WBAK, KC_WFWD), ENCODER_CCW_CW(KC_WBAK, KC_WFWD), \
                        ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_SPC, KC_ENT), ENCODER_CCW_CW(KC_SPC, KC_ENT), ENCODER_CCW_CW(KC_DOWN, KC_UP), ENCODER_CCW_CW(KC_DOWN, KC_UP)}
#    define ENCODER_CCW_CW_2 {ENCODER_CCW_CW(RGB_SPD, RGB_SPI), ENCODER_CCW_CW(RGB_SPD, RGB_SPI), ENCODER_CCW_CW(RGB_SAD, RGB_SAI), ENCODER_CCW_CW(RGB_SAD, RGB_SAI), ENCODER_CCW_CW(RGB_RMOD, RGB_MOD), ENCODER_CCW_CW(RGB_RMOD, RGB_MOD), \
                        ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(RGB_SAD, RGB_SAI), ENCODER_CCW_CW(RGB_SAD, RGB_SAI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI)}
#    define ENCODER_CCW_CW_3 {ENCODER_CCW_CW(RGB_SAD, RGB_SAI), ENCODER_CCW_CW(RGB_SAD, RGB_SAI), ENCODER_CCW_CW(RGB_RMOD, RGB_MOD), ENCODER_CCW_CW(RGB_RMOD, RGB_MOD), ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(RGB_HUD, RGB_HUI), \
                        ENCODER_CCW_CW(RGB_SAD, RGB_SAI), ENCODER_CCW_CW(RGB_SAD, RGB_SAI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(KC_DOWN, KC_UP), ENCODER_CCW_CW(KC_DOWN, KC_UP)}
#    define ENCODER_CCW_CW_4 {ENCODER_CCW_CW(RGB_RMOD, RGB_MOD), ENCODER_CCW_CW(RGB_RMOD, RGB_MOD), ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(RGB_SAD, RGB_SAI), ENCODER_CCW_CW(RGB_SAD, RGB_SAI), \
                        ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(KC_DOWN, KC_UP), ENCODER_CCW_CW(KC_DOWN, KC_UP), ENCODER_CCW_CW(KC_SPC, KC_ENT), ENCODER_CCW_CW(KC_SPC, KC_ENT)}
//                  Encoder 1                                     Encoder 2
#endif