#include QMK_KEYBOARD_H
//#include "../common/matrix_remap.h"

#define LED_NUMLOCK_INDEX 0
#define LED_RGBLIGHT_START_INDEX 1

extern matrix_row_t matrix[MATRIX_ROWS]; // debounced values
bool                mac_mode = false;

void keyboard_post_init_kb(void) {
    //    rgblight_set_clipping_range(LED_RGBLIGHT_START_INDEX, 6);
    rgblight_set_effect_range(LED_RGBLIGHT_START_INDEX, 6);
    keyboard_post_init_user();
}

// bool led_update_kb(led_t led_state) {
//     if (led_state.num_lock) {
//         rgblight_setrgb_at(255, 255, 255, LED_NUMLOCK_INDEX);
//     } else {
//         rgblight_setrgb_at(0, 0, 0, LED_NUMLOCK_INDEX);
//     }
//     return true;
// }

void led_update_ports(led_t led_state) {
    if (mac_mode) return;
    if (led_state.num_lock) {
        rgblight_sethsv_at(HSV_WHITE, LED_NUMLOCK_INDEX);
    } else {
        rgblight_sethsv_at(HSV_TEAL, LED_NUMLOCK_INDEX);
    }
}

bool process_detected_host_os_kb(os_variant_t os_type) {
    if (!process_detected_host_os_user(os_type)) {
        return false;
    }
    switch (os_type) {
        case OS_MACOS:
            mac_mode = true;
            rgblight_sethsv_at(HSV_PINK, LED_NUMLOCK_INDEX);
            break;
        default:
            mac_mode = false;
            return false;
    }
    return true;
}

// void matrix_scan_kb(void) {
//     matrix_remap(matrix);
//     matrix_scan_user();
// }