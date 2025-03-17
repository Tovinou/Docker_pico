#ifndef ALARM_H
#define ALARM_H

#include <stdint.h>
#include <stdbool.h>

// Initialize alarm system
void alarm_init(void);

// Check conditions and trigger alarm if needed
void alarm_check_conditions(uint16_t x_value, uint16_t y_value, float sensor_value);

// Control alarm state
void alarm_on(void);
void alarm_off(void);
void alarm_enable(void);
void alarm_disable(void);

#endif // ALARM_H 