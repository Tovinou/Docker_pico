#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "joystick.h"

// Joystick pins
#define X_AXIS_PIN 26  // ADC0
#define Y_AXIS_PIN 27  // ADC1
#define BUTTON_PIN 28

void joystick_init(void) {
    // Initialize ADC
    adc_init();
    adc_gpio_init(X_AXIS_PIN);
    adc_gpio_init(Y_AXIS_PIN);

    // Initialize button
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);
}

void joystick_read(uint16_t *x_value, uint16_t *y_value, bool *button_state) {
    // Read X-axis (ADC0)
    adc_select_input(0);
    *x_value = adc_read();

    // Read Y-axis (ADC1)
    adc_select_input(1);
    *y_value = adc_read();

    // Read button state (active low due to pull-up)
    *button_state = gpio_get(BUTTON_PIN);
} 