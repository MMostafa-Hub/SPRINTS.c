/*
 * lcd.h
 *
 * Created: 16/9/2021 2:26:11 PM
 *  Author: OWNER
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "../macros.h"

void lcd_init(void);
void lcd_cmd(int data);
void Lcd_Set_Cursor(char a, char b);
void lcd_write_char(int data);
void lcd_write_string(char* str);
void lcd_clear(void);

#endif /* LCD_H_ */