/*
 * lcd.c
 *
 * Created: 11/10/2021 6:55:26 PM
 *  Author: OWNER
 */ 
#include "../DIO_Driver/dio.h"
#include "../Timer_Driver/timer.h"
#include "../Led_Driver/led.h"
#include "../macros.h"

void lcd_cmd(int data)
{
	
	lcd_control	&= ~(1 << RS);
	lcd_data = data;
	lcd_control |= (1 << EN);
	timer_delay(1);
	lcd_control &= ~(1 << EN);
	timer_delay(1);

}

void lcd_init(void)
{
	DDRD = 0xf0;
	DDRC = 0x07;

	lcd_control	&= ~(1 << RS);
	lcd_control &= ~(1 << RW);
	lcd_control &= ~(1 << EN);



	lcd_cmd(0x38);    //function set 8-bit, 2-line display , 5x8 dots
	lcd_cmd(0x0c);    //display on,cursor off,blink off
	lcd_cmd(0x01);    //clear display
	lcd_cmd(0x06);    //entry mode, set increment
}



void Lcd_Set_Cursor(char a, char b)
{
	if(a == 1)
	lcd_cmd(0x80 + b);
	else if(a == 2)
	lcd_cmd(0xC0 + b);
}

void lcd_write_char(int data)
{
	
	lcd_control	|= (1 << RS);
	lcd_data = data;
	lcd_control |= (1 << EN);
	timer_delay(1);
	lcd_control &= ~(1 << EN);
	timer_delay(1);
}


void lcd_write_string(char* str)
{
	for(int i = 0 ; str[i] != '\0' ; i++)
	{
		lcd_write_char(str[i]);
	}
	
}


void lcd_clear(void)
{
	lcd_cmd(0x01);
}