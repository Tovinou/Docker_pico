#ifndef SERVER_2_H
#define SERVER_2_H

#include <stdint.h>

void server_init(void);
void server_update_data(uint16_t x_value, uint16_t y_value, float sensor_value);

#endif // SERVER_2_H 