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

void timer_init(int time)
{	
	double timeToOverflow = CyclesToOverFlowNormal * 1.024; // 262.144
	int nIterations = (int)(time / timeToOverflow); // 1
	int extra = time % (int)(ceil(timeToOverflow)); // 37
	int extra_TCNT0_initial_value = timeToOverflow - extra; // 256 - 37 = 219
	
	Timer0_control = 0b00000101;	// Timer0, normal mode, /1024 pre-scalar 
	for(int iterator = 0 ; iterator < nIterations ;iterator++)
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




int delayTime ; //global
void __vector_9 (void) __attribute__ ((signal,used)) ;
void __vector_9 (void) // Timer1 ISR // executed if TOV1 is set in TIFR
{
	DIO_write(PORTA_Data_addr,DIo_read(PORTA_Data_addr)^0x01);
	TCNT1 = delayTime;   
}
void timer_init_interr(int time) // Timer 1 
{
	delayTime = ceil(CyclesToOverFlowInterr - time/1.024);
	TCNT1 =  delayTime;  // combines TCNT1H and TCNT1L
	
	Timer1_control_regA = 0x00;
	Timer1_control_regB = 0b00000101;  // Timer mode with 1024 prescler
	Timer1_interr_mask = 0x04 ;   // Enable timer1 overflow interrupt(TOIE1)
	sei();        // Enable global interrupts by setting global interrupt enable bit in SREG
}

