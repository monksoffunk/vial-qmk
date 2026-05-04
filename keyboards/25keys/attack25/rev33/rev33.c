#include QMK_KEYBOARD_H
#include "os_detection.h"
#include "../common/attack25_defaults.h"
#include "../common/matrix_remap.h"
#ifdef VIA_ENABLE
#    include "via.h"
#endif

#define OS_DETECTION_SINGLE_REPORT
#define LED_NUMLOCK_INDEX 0
#define LED_RGBLIGHT_START_INDEX 1
#define NUMLOCK_COLOR_LAYOUT_OPTION_SHIFT 0
#define NUMLOCK_COLOR_LAYOUT_OPTION_MASK 0x0F
#define ALL_LEDS_OFF_LAYOUT_OPTION_SHIFT 4
#define ALL_LEDS_OFF_LAYOUT_OPTION_MASK 0x01

extern matrix_row_t matrix[MATRIX_ROWS]; // debounced values
user_config_t       user_config;
bool                numlock_mode      = true;
bool                numlock_init_done = false;
static uint16_t     numcheck_timer;
static uint8_t      numlock_color_choice;
static bool         underglow_soft_off;
static bool         all_leds_force_off;

static void set_numlock_indicator_color(void) {
    if (numlock_color_choice == 1) {
        rgblight_sethsv_at(HSV_RED, LED_NUMLOCK_INDEX);
    } else if (numlock_color_choice == 2) {
        rgblight_sethsv_at(HSV_ORANGE, LED_NUMLOCK_INDEX);
    } else if (numlock_color_choice == 3) {
        rgblight_sethsv_at(HSV_YELLOW, LED_NUMLOCK_INDEX);
    } else if (numlock_color_choice == 4) {
        rgblight_sethsv_at(HSV_GREEN, LED_NUMLOCK_INDEX);
    } else if (numlock_color_choice == 5) {
        rgblight_sethsv_at(HSV_CYAN, LED_NUMLOCK_INDEX);
    } else if (numlock_color_choice == 6) {
        rgblight_sethsv_at(HSV_AZURE, LED_NUMLOCK_INDEX);
    } else if (numlock_color_choice == 7) {
        rgblight_sethsv_at(HSV_BLUE, LED_NUMLOCK_INDEX);
    } else if (numlock_color_choice == 8) {
        rgblight_sethsv_at(HSV_PURPLE, LED_NUMLOCK_INDEX);
    } else if (numlock_color_choice == 9) {
        rgblight_sethsv_at(HSV_MAGENTA, LED_NUMLOCK_INDEX);
    } else if (numlock_color_choice == 10) {
        rgblight_sethsv_at(HSV_WHITE, LED_NUMLOCK_INDEX);
    } else {
        rgblight_sethsv_at(NUMLOCK_INDICATOR_COLOR, LED_NUMLOCK_INDEX);
    }
}

static void refresh_numlock_indicator(void) {
    if (all_leds_force_off) {
        rgblight_setrgb_at(0, 0, 0, LED_NUMLOCK_INDEX);
        return;
    }

    if (user_config.mac_mode) {
        if (numlock_mode) {
            set_numlock_indicator_color();
        } else {
            rgblight_sethsv_at(HSV_WHITE, LED_NUMLOCK_INDEX);
        }
    } else {
        led_t led_state = host_keyboard_led_state();
        if (led_state.num_lock) {
            set_numlock_indicator_color();
        } else {
            rgblight_sethsv_at(HSV_TEAL, LED_NUMLOCK_INDEX);
        }
    }
}

static void apply_underglow_state(void) {
    if (!rgblight_is_enabled()) {
        rgblight_enable_noeeprom();
    }

    if (all_leds_force_off || underglow_soft_off) {
        rgblight_timer_disable();
        rgblight_setrgb(0, 0, 0);
    } else {
        rgblight_mode_noeeprom(rgblight_get_mode());
    }
}

#ifdef VIA_ENABLE
void via_set_layout_options_kb(uint32_t value) {
    numlock_color_choice = (value >> NUMLOCK_COLOR_LAYOUT_OPTION_SHIFT) & NUMLOCK_COLOR_LAYOUT_OPTION_MASK;
    all_leds_force_off   = (value >> ALL_LEDS_OFF_LAYOUT_OPTION_SHIFT) & ALL_LEDS_OFF_LAYOUT_OPTION_MASK;
    apply_underglow_state();
    refresh_numlock_indicator();
}
#endif

void eeconfig_init_kb(void) {
    user_config.raw      = 0;
    user_config.mac_mode = true;
    eeconfig_update_user(user_config.raw);
    eeconfig_init_user();
}

void keyboard_pre_init_kb(void) {
    user_config.raw = eeconfig_read_user();
    numcheck_timer  = timer_read();
    keyboard_pre_init_user();
}

void keyboard_post_init_kb(void) {
    //    rgblight_set_clipping_range(LED_RGBLIGHT_START_INDEX, 6);
    rgblight_set_effect_range(LED_RGBLIGHT_START_INDEX, 6);
    keyboard_post_init_user();
}

void led_update_ports(led_t led_state) {
    if (user_config.mac_mode) return;
    if (led_state.num_lock) {
        set_numlock_indicator_color();
    } else {
        rgblight_sethsv_at(HSV_TEAL, LED_NUMLOCK_INDEX);
    }
}

bool process_detected_host_os_kb(os_variant_t os_type) {
    if (!process_detected_host_os_user(os_type)) {
        return false;
    }
    bool mac_mode = (os_type == OS_MACOS);
    if (user_config.mac_mode != mac_mode) {
        user_config.mac_mode = mac_mode;
        numlock_init_done    = false;
        numcheck_timer       = timer_read();
    }
    if (user_config.mac_mode) {
        set_numlock_indicator_color();
        numlock_mode = true;
    }
    return true;
}

static void numlock_state_check(void) {
    if (!user_config.mac_mode) {
        led_t led_state = host_keyboard_led_state();
        numlock_mode    = (led_state.num_lock && !IS_LAYER_ON(_NUMOFF));
    }
}

void matrix_scan_kb(void) {
    matrix_remap(matrix);

    if (user_config.mac_mode && !numlock_init_done) {
        if (timer_elapsed(numcheck_timer) > 500) {
            if (!host_keyboard_led_state().num_lock) {
                tap_code16(KC_NUM_LOCK);
            }
            numlock_init_done = true;
        }
    }

    numlock_state_check();
    matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case WINMAC:
            if (record->event.pressed) {
                user_config.mac_mode = !user_config.mac_mode;
                eeconfig_update_user(user_config.raw);
                if (user_config.mac_mode && !numlock_mode) {
                    tap_code16(KC_NUM_LOCK);
                    layer_on(_NUMOFF);
                    default_layer_or(1UL << _NUMOFF);
                } else if (!user_config.mac_mode && !numlock_mode) {
                    tap_code16(KC_NUM_LOCK);
                    layer_clear();
                    default_layer_xor(1UL << _NUMOFF);
                }
            }
            return false;
        case KC_NUM:
            if (record->event.pressed) {
                if (user_config.mac_mode) {
                    numlock_mode = !numlock_mode;
                    if (numlock_mode) {
                        layer_off(_NUMOFF);
                        default_layer_xor(1UL << _NUMOFF);
                        set_numlock_indicator_color();
                    } else {
                        layer_on(_NUMOFF);
                        default_layer_or(1UL << _NUMOFF);
                        rgblight_sethsv_at(HSV_WHITE, LED_NUMLOCK_INDEX);
                    }
                    return false;
                }
                return true;
            }
            return !user_config.mac_mode;
        case UG_TOGG:
            if (record->event.pressed) {
                underglow_soft_off = !underglow_soft_off;
                apply_underglow_state();
                refresh_numlock_indicator();
            }
            return false;
        // case RGBRST:
        //     if (record->event.pressed) {
        //         eeconfig_update_rgblight_default();
        //         rgblight_enable();
        //     }
        //     return false;
        case P00:
            if (record->event.pressed) {
                tap_code(KC_P0);
                tap_code(KC_P0);
            }
            return false;
    }
    return process_record_user(keycode, record);
}
