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
#define CyclesToOverFlow 256

void Fast_PWM(uint8_t OCR0_)
{
	////Controlling the speed of the motors using Fast PWM , Timer0, 1/128 preScaler
	DDRB |= (1<<PORTB3);
	TCCR0 |= (1<<WGM01) | (1<<WGM00) | (1<<COM01) | (1<<CS00) | (1<<CS02);
	TCCR0 &= ~(1<<COM00) | ~(1<<CS01);
	OCR0 = OCR0_; // 10/256 * 100 % of full speed
}


void _delay_ms(int time)
{
	double timeToOverflow = CyclesToOverFlow * 1.024; // 262.144
	int nIterations = (int)(time / timeToOverflow); // 1
	int extra = time % (int)(ceil(timeToOverflow)); // 37
	int extra_TCNT0_initial_value = (timeToOverflow - extra)/1.024; // 262.144 - 37 = 225.144
	
	TCCR0 = 0b00000101;	// Timer0, normal mode, /1024 pre-scalar
	for(int iterator = 0 ; iterator < nIterations ;iterator++)
	{
		TCNT0 = 0x00;
		while((TIFR & (1<<TOV0)) == 0);  // Wait for TOV0 to roll overs
		TIFR = 0x01;	// Clear TOV0 flag
	}
	
	TCNT0 = extra_TCNT0_initial_value; // setting the initial value of TCVTO to be 256 - 37 = 219
	while((TIFR & (1<<TOV0)) == 0);
	TIFR = 0x01;  		// Clear TOV0 flag
	TCNT0 = 0x00; // disable timer0
}

#endif /* TIMER_H_ */