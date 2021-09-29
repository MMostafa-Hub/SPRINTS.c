/*
 * timer.h
 *
 * Created: 16/9/2021 2:41:40 PM
 *  Author: OWNER
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../macros.h"
#include "../DIO_Driver/dio.h"
#define CyclesToOverFlowOneByte 255 // 2^8 - 1
#define CyclesToOverFlowTwoBytes 65535 // 2^16 - 1
#define preScaler 1.024
#define timeToOverflowOneByte 261.12
#define timeToOverflowTwoByte 67108.864

void timer_delay(uint16_t time)
{
	if(time > 0)
	{
		Timer0_control = 0b00000101;	// Timer0, normal mode, /1024 pre-scalar
		int nIterations = (int)(time / timeToOverflowOneByte); // 1
		int extra = time % (int)((timeToOverflowOneByte)); // 37
		int extra_TCNT0_initial_value = (int)((timeToOverflowOneByte - extra)/preScaler); // 262.144 - 37 = 225.144
		
		
		for(int iterator = 0 ; iterator < nIterations ;++iterator)
		{
			Timer0_data = 0x00;
			while(Timer0_overflow_flag == 0);  // Wait for TOV0 to roll overs
			Timer_flags = 0x01;	// Clear TOV0 flag
		}
		
		Timer0_data = extra_TCNT0_initial_value; // setting the initial value of TCVTO to be 256 - 37 = 219
		while(Timer0_overflow_flag == 0);
		Timer_flags = 0x01;  		// Clear TOV0 flag
		Timer0_control = 0x00; // disable timer0
		
	}
}




extern uint8_t gu8_timeIsOverFlag;

void __vector_9 (void) __attribute__ ((signal,used)) ;
void __vector_9 (void) // Timer1 ISR // executed if TOV1 is set in TIFR
{
	gu8_timeIsOverFlag = 1;
	cli();
}
void timer_init_interr(int time) // Timer 1
{
	TCNT1 =  floor(CyclesToOverFlowTwoBytes - time/1.024);  // combines TCNT1H and TCNT1L
	
	Timer1_control_regA = 0x00;
	Timer1_control_regB = 0b00000101;  // Timer mode with 1024 prescler
	Timer1_interr_mask = 0x04 ;   // Enable timer1 overflow interrupt(TOIE1)
	sei();        // Enable global interrupts by setting global interrupt enable bit in SREG
}



#endif /* TIMER_H_ */