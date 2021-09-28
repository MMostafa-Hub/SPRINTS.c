/*
* Task3_GuessingGameV2.c
*
* Created: 18/9/2021 11:07:01 AM
* Author : OWNER
*/

#include "app.h"



int main(void)
{
	app_init();
	uint8_t input = 0;
	uint8_t i = 0;
	uint8_t seed = 0;
	char sinput[5];
	memset(sinput,'\0', 5);
	
	while(1)
	{
		
		if(!timeIsOver)
		{
			int8_t key = keypad();
			render_main_screen();
			if(key == invalid)
			{
				render_invalid_input_screen();
			}
			else if(key != none)
			{
				sinput[i] = key;
				lcd_write_string(sinput);
				_delay_ms(300);
				i++;
				timer_init_interr(1000);

			}
			
		}
		else
		{
			
			uint8_t randNumber = rand_int(seed);
			char sRandNumber[2] ;
			itoa(randNumber,sRandNumber,10);
			
			input = atoi(sinput);
			if(input > 15 || input == 0)
			{
				render_range_invalid_screen();
			}
			else if(input == randNumber)
			{
				render_win_screen(sRandNumber);
			}
			else
			{
				render_loss_screen(sRandNumber);
			}
			_delay_ms(500);
			timeIsOver = 0;
			memset(sinput,'\0', 5);
			i = 0; 

		}
		seed++;
	}
}


