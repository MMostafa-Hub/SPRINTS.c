/*
 * app.c
 *
 * Created: 11/10/2021 8:41:50 PM
 *  Author: OWNER
 */ 
#include "lcd_Driver/lcd.h"
#include "Button_Driver/button.h"
#include "Led_Driver/led.h"
#include "Timer_Driver/timer.h"

void app_init(void)
{
	lcd_init();
	button_init(&PORTB_Data,&PORTB_Dir,btn);
	
	/* the two leds are used for debugging */
	led_init(&PORTA_Data,&PORTA_Dir,red_led);
	led_init(&PORTA_Data,&PORTA_Dir,yellow_led);

}


void render_main_screen(void)
{
	Lcd_Set_Cursor(1,0);
	lcd_write_string("Please Guess");
	Lcd_Set_Cursor(2,0);
	lcd_write_string("an Integer:");
}
void render_win_screen(char* rand_number)
{
	lcd_cmd(0x01);
	Lcd_Set_Cursor(1,4); // to make the sentence centered
	lcd_write_string("YOU WON");
	Lcd_Set_Cursor(2,0);
	lcd_write_string("it was :");
	lcd_write_string(rand_number);
	timer_delay(2000);
	lcd_cmd(0x01);
}
void render_loss_screen(char* rand_number)
{
	lcd_cmd(0x01);
	Lcd_Set_Cursor(1,4);// to make the sentence centered
	lcd_write_string("YOU LOST");
	Lcd_Set_Cursor(2,0);
	lcd_write_string("it was :");
	lcd_write_string(rand_number);
	timer_delay(2000);
	lcd_cmd(0x01);
}
void render_range_invalid_screen()
{
	lcd_cmd(0x01);
	Lcd_Set_Cursor(1,0);
	lcd_write_string("The Valid Range");
	Lcd_Set_Cursor(2,0);
	lcd_write_string("from 1 -> 15:");
	timer_delay(2000);
	lcd_cmd(0x01);
}
uint8_t rand_int(uint8_t seed,uint8_t range)
{
	srand(seed);
	return (rand()%(range-1)+1); // random number between 1 and 15 inclusive
}