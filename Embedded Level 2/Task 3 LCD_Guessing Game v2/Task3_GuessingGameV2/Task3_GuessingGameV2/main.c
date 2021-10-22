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
	
	uint8_t input = 0; // the integer value the user's input
	uint8_t i = 0; // iterator of the sInput
	uint8_t seed = 0; // the seed of the random number generator
	
	char sinput[5];  // the string value of the user's input
	memset(sinput,'\0', 5); // sets all the values of sinput to '\0'
	
	while(1)
	{
		
		int8_t key = keypad(); // get the keypad status
		render_main_screen();
		if(key == invalid) // if the key pressed was invalid
		{
			render_invalid_input_screen();
		}
		else if (key == ENTER)
		{
			if(sinput[0] == '\0') // Ignore ENTER if the user didn't input any data
				continue;				
			
			uint8_t randNumber = rand_int(seed,15); // generate a random number from 1 to 15
			char sRandNumber[2] ;
			itoa(randNumber,sRandNumber,10); // converting the number INTEGER into string
					
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
			memset(sinput,'\0', 5);
			i = 0;

		}
		else if(key != none) // if the user did press a number
		{
			sinput[i] = key; // push the key into sinput 
			lcd_write_string(sinput); 
			timer_delay(200); // delay to prevent long presses
			i++; 
		}
		seed++; 
	}
}


