/*
 * timer.c
 *
 * Created: 6/9/2021 10:39:46 PM
 *  Author: OWNER
 */ 
#include "../registers.h"
#include <math.h>
#define CyclesToOverFlow 256

void timer_init(int time)
{	
	double timeToOverflow = CyclesToOverFlow * 1.024; // 262.144
	int nIterations = (int)(time / timeToOverflow); // 1
	int extra = time % (int)(ceil(timeToOverflow)); // 37
	int extra_TCNT0_initial_value = timeToOverflow - extra; // 256 - 37 = 219
	
	Timer_control = 0b00000101;	// Timer0, normal mode, /1024 pre-scalar 
	for(int iterator = 0 ; iterator < nIterations ;iterator++)
	{
		Timer_data = 0x00;
		while(Timer_overflow_flag == 0);  // Wait for TOV0 to roll overs
		Timer_flags = 0x01;	// Clear TOV0 flag
	}
	
	Timer_data = extra_TCNT0_initial_value; // setting the initial value of TCVTO to be 256 - 37 = 219
	while(Timer_overflow_flag == 0);
	Timer_flags = 0x01;  		// Clear TOV0 flag 
	Timer_control = 0x00; // disable timer0
}