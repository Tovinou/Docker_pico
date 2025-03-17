#ifndef LCD_H
#define LCD_H

#include "pico/stdlib.h"

// LCD pins
#define LCD_RS_PIN 16
#define LCD_E_PIN  17
#define LCD_D4_PIN 18
#define LCD_D5_PIN 19
#define LCD_D6_PIN 20
#define LCD_D7_PIN 21

// LCD dimensions
#define LCD_ROWS 2
#define LCD_COLS 16

// Function declarations
void lcd_init(void);
void lcd_clear(void);
void lcd_set_cursor(uint8_t col, uint8_t row);
void lcd_string(const char *str);
void lcd_print_char(char c);

#endif // LCD_H 