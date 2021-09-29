/*
* Task3_GuessingGameV2.c
*
* Created: 18/9/2021 11:07:01 AM
* Author : OWNER
*/

#include "app.h"

uint8_t gu8_timeIsOverFlag = 0; // 1 if the user finished his input 0 other wise

int main(void)
{
	app_init();
	uint8_t input = 0; // the integer value the user's input
	uint8_t i = 0; // iterator of the sInput
	uint8_t seed = 0; // the seed of the random number generator
	char sinput[5];  // the string value of the user's input
	memset(sinput,'\0', 5);
	
	while(1)
	{
		
		if(!gu8_timeIsOverFlag) // if the user didn't finish his input
		{
			int8_t key = keypad(); // get the keypad status
			render_main_screen();
			if(key == invalid) // if the key pressed was invalid
			{
				render_invalid_input_screen();
			}
			else if(key != none) // if the user did press any key
			{
				sinput[i] = key; // push the key into sinput 
				lcd_write_string(sinput); 
				timer_delay(200); // delay to prevent long presses
				i++; 
				
				// start a 1 sec timer if the user didn't press any other key
				// the program will consider the user finished his input
				timer_init_interr(1000); 

			}
			
		}
		else
		{
			
			uint8_t randNumber = rand_int(seed); // generate a random number from 1 to 15
			char sRandNumber[2] ;
			itoa(randNumber,sRandNumber,10); // converting the number into string
			
			input = atoi(sinput); // converting the input from the user from string into integer
			if(input > 15 || input == 0) // if input us not in the valid range
			{
				render_range_invalid_screen();
			}
			else if(input == randNumber) // if the input the same as the random number 
			{
				render_win_screen(sRandNumber);
			}
			else // if the input was NOT equal to the random number
			{
				render_loss_screen(sRandNumber);
			}
			
			timer_delay(500); 
			// clearing the variables and repeating the game
			gu8_timeIsOverFlag = 0; 
			memset(sinput,'\0', 5);
			i = 0; 

		}
		seed++; 
	}
}


