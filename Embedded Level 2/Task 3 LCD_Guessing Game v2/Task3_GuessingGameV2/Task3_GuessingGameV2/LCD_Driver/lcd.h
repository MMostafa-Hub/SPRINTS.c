/*
 * lcd.h
 *
 * Created: 16/9/2021 2:26:11 PM
 *  Author: OWNER
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "../macros.h"
void lcd_cmd(int data);
void Lcd_Set_Cursor(uint8_t a, uint8_t b);
void lcd_write_char(int data);
void lcd_write_string(char* str);
void lcd_init(void);




#endif /* LCD_H_ */