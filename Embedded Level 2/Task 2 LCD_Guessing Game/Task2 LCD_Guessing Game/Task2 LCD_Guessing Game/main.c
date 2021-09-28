/*
* Task2 LCD_Guessing Game.c
*
* Created: 13/9/2021 4:53:56 PM
* Author : OWNER
*/


#include "macros.h"
#include "app.h"


int main()
{

	app_init();
	uint8_t nPresses  = 0;

	for(int seed = 0;1;seed++)
	{

		render_main_screen();
		if(timeIsOver)
		{
			uint8_t number = rand_int(seed);
			char snumber[2] ;
			itoa(number,snumber,10);
			
			lcd_cmd(0x01);

			if(nPresses > 15)
			{
				render_range_invalid_screen();
			}
			else if(nPresses == number)
			{
				render_win_screen(snumber);
			}
			else
			{
				render_loss_screen(snumber);
			}
			timeIsOver = 0;
			nPresses = 0;
		}
		else
		{
			led_write(&PORTA_Data,red_led,OFF);
			led_write(&PORTA_Data,yellow_led,OFF);
		}
		
		if(button_pressed(&PORTB_Pin,2))
		{
			timer_init_interr(2000);
			led_write(&PORTA_Data,PORTA0,ON);
			_delay_ms(50);
			nPresses++;
		}
		
	}
}