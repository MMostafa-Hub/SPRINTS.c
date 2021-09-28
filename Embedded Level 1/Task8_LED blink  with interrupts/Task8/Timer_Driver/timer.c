/*
* timer.c
*
* Created: 6/9/2021 10:39:46 PM
*  Author: OWNER
*/
#include <avr/interrupt.h>
#include "../registers.h"
#include "../DIO_Driver/DIO.h"
#include <math.h>
#define CyclesToOverFlowNormal 256 // 2^8
#define CyclesToOverFlowInterr 65536 // 2^16
#define preScaler 1.024


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


void timer_interr_init(void)
{
	Timer1_control_regA = 0x00;
	Timer1_control_regB = 0b00000101;  // Timer mode with 1024 prescler
}

uint16_t gu16_delayTime ; //global
void __vector_9 (void) __attribute__ ((signal,used)) ;
void __vector_9 (void) // Timer1 ISR // executed if TOV1 is set in TIFR
{
	DIO_write(PORTA_Data_addr,DIo_read(PORTA_Data_addr)^0x01); // flipping the bit
	TCNT1 = gu16_delayTime;
}
void timer_interr_delay(int time) // Timer 1
{
	gu16_delayTime = ceil(CyclesToOverFlowInterr - time/preScaler);
	TCNT1 =  gu16_delayTime;  // combines TCNT1H and TCNT1L
	Timer1_interr_mask = 0x04 ;   // Enable timer1 overflow interrupt(TOIE1)
	sei();        // Enable global interrupts by setting global interrupt enable bit in SREG
}
