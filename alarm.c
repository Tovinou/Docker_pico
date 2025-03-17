#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "alarm.h"
#include "lcd.h"

// Define pins
#define BUZZER_PIN 22  // PWM pin for buzzer
#define LED_PIN 25     // Built-in LED

// Alarm thresholds
#define DISTANCE_THRESHOLD 10.0f  // cm
#define JOYSTICK_THRESHOLD 3000   // ADC value

// Alarm states
static bool alarm_enabled = true;
static bool alarm_triggered = false;
static uint slice_num;

void alarm_init(void) {
    // Initialize buzzer pin as PWM
    gpio_set_function(BUZZER_PIN, GPIO_FUNC_PWM);
    slice_num = pwm_gpio_to_slice_num(BUZZER_PIN);
    
    // Set PWM frequency (1KHz)
    pwm_set_wrap(slice_num, 12500);
    pwm_set_chan_level(slice_num, PWM_CHAN_A, 6250);
    
    // Initialize LED pin
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    
    // Start with alarm off
    pwm_set_enabled(slice_num, false);
    gpio_put(LED_PIN, 0);
}

void alarm_check_conditions(uint16_t x_value, uint16_t y_value, float sensor_value) {
    if (!alarm_enabled) return;

    bool should_trigger = false;

    // Check distance threshold
    if (sensor_value > 0 && sensor_value < DISTANCE_THRESHOLD) {
        should_trigger = true;
    }

    // Check joystick extreme positions
    if (x_value > JOYSTICK_THRESHOLD || y_value > JOYSTICK_THRESHOLD) {
        should_trigger = true;
    }

    if (should_trigger && !alarm_triggered) {
        alarm_triggered = true;
        alarm_on();
    } else if (!should_trigger && alarm_triggered) {
        alarm_triggered = false;
        alarm_off();
    }
}

void alarm_on(void) {
    // Turn on buzzer
    pwm_set_enabled(slice_num, true);
    
    // Turn on LED
    gpio_put(LED_PIN, 1);
    
    // Update LCD with alarm message
    lcd_clear();
    lcd_set_cursor(0, 0);
    lcd_string("!! ALARM !!");
    lcd_set_cursor(0, 1);
    lcd_string("Intrusion Detect");
}

void alarm_off(void) {
    // Turn off buzzer
    pwm_set_enabled(slice_num, false);
    
    // Turn off LED
    gpio_put(LED_PIN, 0);
}

void alarm_enable(void) {
    alarm_enabled = true;
}

void alarm_disable(void) {
    alarm_enabled = false;
    alarm_off();
} 