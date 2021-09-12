/*
* timer.h
*
* Created: 8/9/2021 6:01:10 PM
*  Author: OWNER
*/


#ifndef TIMER_H_
#define TIMER_H_
#include "../macros.h"
#include <math.h>

void Fast_PWM(uint8_t OCR0_)
{
	////Controlling the speed of the motors using Fast PWM , Timer0, 1/1024 preScaler , non-inverting
	PORTB_Dir |= (1<<3);
	
	Timer0_control = 0b01101101;
	Timer0_Compare = OCR0_; // OCR0_/256 * 100 % of full speed
}


#endif /* TIMER_H_ */