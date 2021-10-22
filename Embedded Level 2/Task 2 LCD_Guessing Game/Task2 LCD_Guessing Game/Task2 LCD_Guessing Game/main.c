/*
* Task2 LCD_Guessing Game.c
*
* Created: 13/9/2021 4:53:56 PM
* Author : OWNER
*/


#include "macros.h"
#include "app.h"

uint8_t gu8_timeIsOverFlag = 0; // flag is 1 if the user finished entering the data
int main()
{

	app_init();
	uint8_t nPresses  = 0, prevButton = 0, currentButton = 0; // counts the number of presses 
	
	for(uint8_t seed = 0;True;++seed) // every iteration changes the seed of the random number generator
	{

		render_main_screen();
		if(gu8_timeIsOverFlag) // if the time is up
		{
			uint8_t rand_number = 4; // generates a random number in the range of 1 -> 15
			char s_rand_number[2] ;
			itoa(rand_number,s_rand_number,10); // convert number from int into string and saves it in snumber
			
			lcd_clear(); // clears the screen

			if(nPresses > 15) // if number of presses is more than 15 
			{
				render_range_invalid_screen(); 
			}
			else if(nPresses == rand_number) // if number of presses equal to the generated random number
			{
				render_win_screen(s_rand_number);
			}
			else // if the number is not equal to the generated random number
			{
				render_loss_screen(s_rand_number);
			}
			
			
			gu8_timeIsOverFlag = 0; 
			nPresses = 0;
		}
		else // turning off the leds
		{
			led_write(&PORTA_Data,red_led,OFF);
			led_write(&PORTA_Data,yellow_led,OFF);
		}
		

		// if the button got pressed we will increment nPresses, initiate a new delay and turning the red led on
		currentButton =  button_pressed(&PORTB_Pin,btn);
		if(prevButton != currentButton && prevButton) // to prevent long presses
		{
			timer_interr_delay(2000); 
			led_write(&PORTA_Data,red_led,ON);
			timer_delay(50); 
			nPresses++;
		}
		prevButton = currentButton;
	}
}