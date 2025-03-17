#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "sensor.h"

#define TRIG_PIN 14
#define ECHO_PIN 15

void init_ultrasonic(void) {
    gpio_init(TRIG_PIN);
    gpio_init(ECHO_PIN);
    gpio_set_dir(TRIG_PIN, GPIO_OUT);
    gpio_set_dir(ECHO_PIN, GPIO_IN);
    gpio_put(TRIG_PIN, 0);
}

float measure_distance(void) {
    // Send trigger pulse
    gpio_put(TRIG_PIN, 1);
    sleep_us(10);
    gpio_put(TRIG_PIN, 0);
    
    // Wait for echo to start
    uint64_t start = time_us_64();
    while (!gpio_get(ECHO_PIN)) {
        if (time_us_64() - start > 30000) {
            return -1.0f; // Timeout error
        }
    }
    
    // Measure echo duration
    start = time_us_64();
    while (gpio_get(ECHO_PIN)) {
        if (time_us_64() - start > 30000) {
            return -1.0f; // Timeout error
        }
    }
    uint64_t duration = time_us_64() - start;
    
    // Calculate distance in cm (speed of sound = 343m/s)
    float distance = (duration * 0.0343) / 2;
    return distance;
} 