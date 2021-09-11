/*
* CAR.c
*
* Created: 8/9/2021 2:51:48 PM
* Author : OWNER
*/

#include <avr/io.h>
#include "macros.h"
#include "app.h"

#define True 1


int main(void)
{
	
	app_init();
	
	//Initial state of G button
	uint8_t prevG = 0 , nStates = 4;
	int8_t state = -1; //
	while (True)
	{
		uint8_t currentG = is_button_pressed(buttonG) ;
		
		if(prevG != currentG && currentG) // to Avoid long press
		{
			state++; // each press of button G changes the state
		}
		
		if(is_button_pressed(buttonM) && state > -1)// state > -1 to avoid pressing M at the first time we must press G first
		{
			setState(state % nStates); // making the states circulating
		}
		else if(state > -1) // STOP State
		{
			car_stop();
			if(is_button_pressed(buttonL))
			{
				car_rotate_left();
			}
			else if (is_button_pressed(buttonR))
			{
				car_rotate_right();
			}
		}
		
		
		
		prevG = currentG;
	}
}

