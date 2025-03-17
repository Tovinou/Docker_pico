#include <stdio.h>
#include "pico/stdlib.h"
#include "server_2.h"

void server_init(void) {
    // Initialize any server-related hardware or configurations here
    printf("Server initialized\n");
}

void server_update_data(uint16_t x_value, uint16_t y_value, float sensor_value) {
    // For now, just print the values
    printf("Server data update - X: %d, Y: %d, Distance: %.2f cm\n", 
           x_value, y_value, sensor_value);
} 