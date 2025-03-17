#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <stdint.h>
#include <stdbool.h>

void joystick_init(void);
void joystick_read(uint16_t *x_value, uint16_t *y_value, bool *button_state);

#endif // JOYSTICK_H 