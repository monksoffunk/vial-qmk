#include  "quantum.h"
#include "wait.h"

#if defined(ENCODER_MATRIX_ENABLE) 

#ifndef ENCODER_SETTLE_PIN_STATE_DELAY
# define ENCODER_SETTLE_PIN_STATE_DELAY 10
#endif

static pin_t encoder_matrix_col_pins_A[] = ENCODER_MATRIX_COL_PINS_A;
static pin_t encoder_matrix_col_pins_B[] = ENCODER_MATRIX_COL_PINS_B;
static pin_t encoder_matrix_row_pins[] = ENCODER_MATRIX_ROW_PINS;

static inline void gpio_atomic_set_pin_output_low(pin_t pin) {
    ATOMIC_BLOCK_FORCEON {
        gpio_set_pin_output(pin);
        gpio_write_pin_low(pin);
    }
}

static inline void gpio_atomic_set_pin_output_high(pin_t pin) {
    ATOMIC_BLOCK_FORCEON {
        gpio_set_pin_output(pin);
        gpio_write_pin_high(pin);
    }
}
static inline void gpio_atomic_set_pin_input_high(pin_t pin) {
    ATOMIC_BLOCK_FORCEON {
        gpio_set_pin_input_high(pin);
    }
}

void encoder_quadrature_init_pin(uint8_t index, bool pad_b) {
}

uint8_t encoder_quadrature_read_pin(uint8_t index, bool pad_b) {
    pin_t row_pin = encoder_matrix_row_pins[index];
    if (row_pin == NO_PIN) {
        return 0;
    }

    pin_t col_pin = pad_b ? encoder_matrix_col_pins_B[index] : encoder_matrix_col_pins_A[index];
    if (col_pin == NO_PIN) {
        return 0;
    }

    // select encoder row
    gpio_atomic_set_pin_output_low(row_pin);
    matrix_output_select_delay();
    uint8_t ret = gpio_read_pin(col_pin) ? 1 : 0;

    //unselect encoder row
    gpio_atomic_set_pin_input_high(row_pin);
    matrix_output_unselect_delay(row_pin, ret != 0); // wait for all Col signals to go HIGH
    return ret;
}

#endif