#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "lcd.h"
#include "joystick.h"
#include "sensor.h"
#include "server_2.h"
#include "alarm.h"

// Function prototypes
void initialize_all_components(void);
void update_display(uint16_t x_value, uint16_t y_value, float sensor_value);

int main() {
    // Initialize stdio for debug output
    stdio_init_all();
    
    // Initialize all components
    initialize_all_components();
    
    // Main loop
    while (1) {
        // Read joystick values
        uint16_t x_value, y_value;
        bool button_state;
        joystick_read(&x_value, &y_value, &button_state);
        
        // Read sensor value
        float sensor_value = measure_distance();
        
        // Check alarm conditions
        alarm_check_conditions(x_value, y_value, sensor_value);
        
        // Update LCD display
        update_display(x_value, y_value, sensor_value);
        
        // Update server with new values
        server_update_data(x_value, y_value, sensor_value);
        
        // Handle button press
        if (button_state == 0) { // Button is active low
            printf("Button pressed!\n");
            // Toggle alarm system
            static bool alarm_state = true;
            if (alarm_state) {
                alarm_disable();
                lcd_clear();
                lcd_set_cursor(0, 0);
                lcd_string("Alarm Disabled");
            } else {
                alarm_enable();
                lcd_clear();
                lcd_set_cursor(0, 0);
                lcd_string("Alarm Enabled");
            }
            alarm_state = !alarm_state;
            sleep_ms(500); // Debounce
        }
        
        sleep_ms(100); // Main loop delay
    }
    
    return 0;
}

void initialize_all_components(void) {
    // Initialize LCD
    lcd_init();
    lcd_clear();
    lcd_set_cursor(0, 0);
    lcd_string("System Starting...");
    
    // Initialize joystick
    joystick_init();
    
    // Initialize sensor
    init_ultrasonic();
    
    // Initialize alarm
    alarm_init();
    
    // Initialize server
    // server_init(); // Uncomment if server initialization is needed
    
    // Wait for all components to stabilize
    sleep_ms(1000);
    
    lcd_clear();
    lcd_set_cursor(0, 0);
    lcd_string("System Ready!");
    sleep_ms(500);
}

void update_display(uint16_t x_value, uint16_t y_value, float sensor_value) {
    char buffer[32];
    
    lcd_clear();
    
    // First line: Joystick values
    snprintf(buffer, sizeof(buffer), "Joy: X:%d Y:%d", x_value, y_value);
    lcd_set_cursor(0, 0);
    lcd_string(buffer);
    
    // Second line: Sensor value
    snprintf(buffer, sizeof(buffer), "Sensor: %.2f cm", sensor_value);
    lcd_set_cursor(0, 1);
    lcd_string(buffer);
} 