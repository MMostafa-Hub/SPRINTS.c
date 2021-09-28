/*
 * timer.c
 *
 * Created: 28/9/2021 9:28:57 PM
 *  Author: OWNER
 */ 
#include "../macros.h"

void timer_pwm_init(void)
{
	////Controlling the speed of the motors using Fast PWM , Timer0, 1/1024 preScaler , non-inverting
	PORTB_Dir |= (1<<3);
	Timer0_control = 0b01101101;
}
void Fast_PWM(uint8_t OCR0_)
{
	Timer0_Compare = OCR0_; // OCR0_/256 * 100 % of full speed
}




void timer_init(void)
{
	Timer0_control = 0b00000101;	// Timer0, normal mode, /1024 pre-scalar
}

void timer_delay(int time)
{
	if(time > 0){
		
		double double_timeToOverflow = CyclesToOverFlowNormal * preScaler; // 262.144
		int nIterations = (int)(time / double_timeToOverflow); // 1
		int extra = time % (int)((double_timeToOverflow)); // 37
		int extra_TCNT0_initial_value = (int)((double_timeToOverflow - extra)/preScaler); // 262.144 - 37 = 225.144
		
		
		for(int iterator = 0 ; iterator < nIterations ;++iterator)
		{
			Timer0_data = 0x00;
			while(Timer0_overflow_flag == 0);  // Wait for TOV0 to roll overs
			Timer0_flags = 0x01;	// Clear TOV0 flag
		}
		
		Timer0_data = extra_TCNT0_initial_value; // setting the initial value of TCVTO to be 256 - 37 = 219
		while(Timer0_overflow_flag == 0);
		Timer0_flags = 0x01;  		// Clear TOV0 flag
		Timer0_control = 0x00; // disable timer0
	}
}