/*
 * app.h
 *
 * Created: 21/9/2021 6:39:32 PM
 *  Author: OWNER
 */ 


#ifndef APP_H_
#define APP_H_
#include "LCD_Driver/lcd.h"
#include "Button_Driver/button.h"
#include "DIO_Driver/dio.h"
#include "KeyPad_Driver/keypad.h"
#include "Timer_Driver/timer.h"
void app_init(void)
{
	lcd_init();
	DIO_init(&PORTA_Data,&PORTA_Dir,OUTPUT,4);
	DIO_init(&PORTA_Data,&PORTA_Dir,OUTPUT,5);
	DIO_init(&PORTA_Data,&PORTA_Dir,OUTPUT,6);
	DIO_init(&PORTA_Data,&PORTA_Dir,OUTPUT,7);
	
	button_init(&PORTA_Data,&PORTA_Dir,0);
	button_init(&PORTA_Data,&PORTA_Dir,1);
	button_init(&PORTA_Data,&PORTA_Dir,2);
	button_init(&PORTA_Data,&PORTA_Dir,3);

}

void render_main_screen(void)
{
	Lcd_Set_Cursor(1,0);
	lcd_write_string("Please Guess");
	Lcd_Set_Cursor(2,0);
	lcd_write_string("an Integer:");
}
void render_win_screen(char* number)
{
	lcd_cmd(0x01);
	Lcd_Set_Cursor(1,4);
	lcd_write_string("YOU WON");
	Lcd_Set_Cursor(2,0);
	lcd_write_string("it was :");
	lcd_write_string(number);
	timer_delay(2000);
	lcd_cmd(0x01);
}
void render_loss_screen(char* number)
{
	lcd_cmd(0x01);
	Lcd_Set_Cursor(1,4);
	lcd_write_string("YOU LOST");
	Lcd_Set_Cursor(2,0);
	lcd_write_string("it was :");
	lcd_write_string(number);
	timer_delay(2000);
	lcd_cmd(0x01);
}
void render_range_invalid_screen(void)
{
	lcd_cmd(0x01);
	Lcd_Set_Cursor(1,0);
	lcd_write_string("The Valid Range");
	Lcd_Set_Cursor(2,0);
	lcd_write_string("from 1 -> 15:");
	timer_delay(2000);
	lcd_cmd(0x01);
}
void render_invalid_input_screen(void)
{
	lcd_cmd(0x01);
	Lcd_Set_Cursor(1,0);
	lcd_write_string("Invalid Input");
	timer_delay(2000);
	lcd_cmd(0x01);
}
uint8_t rand_int(uint8_t seed)
{
	srand(seed);
	return (rand()%14+1); // random number between 1 and 15 inclusive
}


#endif /* APP_H_ */