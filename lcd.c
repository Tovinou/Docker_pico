#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "lcd.h"

// LCD commands
#define LCD_CLEARDISPLAY    0x01
#define LCD_RETURNHOME      0x02
#define LCD_ENTRYMODESET    0x04
#define LCD_DISPLAYCONTROL  0x08
#define LCD_CURSORSHIFT     0x10
#define LCD_FUNCTIONSET     0x20
#define LCD_SETCGRAMADDR    0x40
#define LCD_SETDDRAMADDR    0x80

// Flags for display entry mode
#define LCD_ENTRYRIGHT          0x00
#define LCD_ENTRYLEFT          0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// Flags for display on/off control
#define LCD_DISPLAYON  0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON   0x02
#define LCD_CURSOROFF  0x00
#define LCD_BLINKON    0x01
#define LCD_BLINKOFF   0x00

// Flags for function set
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE    0x08
#define LCD_1LINE    0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS  0x00

static void lcd_write_4bits(uint8_t data) {
    // Set data pins
    gpio_put(LCD_D4_PIN, (data >> 0) & 1);
    gpio_put(LCD_D5_PIN, (data >> 1) & 1);
    gpio_put(LCD_D6_PIN, (data >> 2) & 1);
    gpio_put(LCD_D7_PIN, (data >> 3) & 1);
    
    // Toggle enable pin
    gpio_put(LCD_E_PIN, 1);
    sleep_us(1);
    gpio_put(LCD_E_PIN, 0);
    sleep_us(100);
}

static void lcd_send_byte(uint8_t val, bool is_command) {
    gpio_put(LCD_RS_PIN, !is_command);
    
    // Send high nibble
    lcd_write_4bits(val >> 4);
    // Send low nibble
    lcd_write_4bits(val);
}

void lcd_init(void) {
    // Initialize pins
    gpio_init(LCD_RS_PIN);
    gpio_init(LCD_E_PIN);
    gpio_init(LCD_D4_PIN);
    gpio_init(LCD_D5_PIN);
    gpio_init(LCD_D6_PIN);
    gpio_init(LCD_D7_PIN);
    
    // Set pins as outputs
    gpio_set_dir(LCD_RS_PIN, GPIO_OUT);
    gpio_set_dir(LCD_E_PIN, GPIO_OUT);
    gpio_set_dir(LCD_D4_PIN, GPIO_OUT);
    gpio_set_dir(LCD_D5_PIN, GPIO_OUT);
    gpio_set_dir(LCD_D6_PIN, GPIO_OUT);
    gpio_set_dir(LCD_D7_PIN, GPIO_OUT);
    
    // Wait for LCD to power up
    sleep_ms(50);
    
    // Initialize LCD in 4-bit mode
    lcd_write_4bits(0x03);
    sleep_ms(5);
    lcd_write_4bits(0x03);
    sleep_us(150);
    lcd_write_4bits(0x03);
    lcd_write_4bits(0x02);
    
    // Function set: 4-bit mode, 2 lines, 5x8 dots
    lcd_send_byte(LCD_FUNCTIONSET | LCD_4BITMODE | LCD_2LINE | LCD_5x8DOTS, true);
    
    // Display control: display on, cursor off, blink off
    lcd_send_byte(LCD_DISPLAYCONTROL | LCD_DISPLAYON | LCD_CURSOROFF | LCD_BLINKOFF, true);
    
    // Entry mode set: increment cursor, no display shift
    lcd_send_byte(LCD_ENTRYMODESET | LCD_ENTRYLEFT | LCD_ENTRYSHIFTDECREMENT, true);
    
    // Clear display
    lcd_clear();
}

void lcd_clear(void) {
    lcd_send_byte(LCD_CLEARDISPLAY, true);
    sleep_ms(2);
}

void lcd_set_cursor(uint8_t col, uint8_t row) {
    static uint8_t row_offsets[] = {0x00, 0x40, 0x14, 0x54};
    if (row >= LCD_ROWS) {
        row = LCD_ROWS - 1;
    }
    if (col >= LCD_COLS) {
        col = LCD_COLS - 1;
    }
    lcd_send_byte(LCD_SETDDRAMADDR | (col + row_offsets[row]), true);
}

void lcd_string(const char *str) {
    while (*str) {
        lcd_print_char(*str++);
    }
}

void lcd_print_char(char c) {
    lcd_send_byte(c, false);
} 