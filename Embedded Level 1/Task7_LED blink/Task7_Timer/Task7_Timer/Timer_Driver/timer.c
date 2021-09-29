/*
 * timer.c
 *
 * Created: 6/9/2021 10:39:46 PM
 *  Author: OWNER
 */ 
#include "../registers.h"
#include <math.h>
#define CyclesToOverFlowOneByte 255 // 2^8
#define CyclesToOverFlowTwoBytes 65535 // 2^16
#define preScaler 1.024

void timer_init(void)
{

}

//void timer_delay(uint16_t time)
//{
	//Timer1_control_regA = 0x00;
	//Timer1_control_regB = 0b00000101;  // Timer mode with 1024 prescler
	//TCNT1 =  (int)(CyclesToOverFlowTwoBytes - time/preScaler);  // combines TCNT1H and TCNT1L
	//while(Timer1_overflow_flag == 0);  // Wait for TOV1 to roll overs
	//Timer_flags = (1<<2);  		// Clear TOV1 flag
//
	//// Disbale Timer1
	//Timer1_control_regA = 0x00;
	//Timer1_control_regB = 0x00;
//}
void timer_delay(uint16_t time)
{

	if(time > 0){
		
		if(time > CyclesToOverFlowOneByte * preScaler)
		{
			Timer0_control = 0b00000101;	// Timer0, normal mode, /1024 pre-scalar
			double double_timeToOverflow = CyclesToOverFlowOneByte * preScaler; // 262.144
			int nIterations = (int)(time / double_timeToOverflow); // 1
			int extra = time % (int)((double_timeToOverflow)); // 37
			int extra_TCNT0_initial_value = (int)((double_timeToOverflow - extra)/preScaler); // 262.144 - 37 = 225.144
			
			
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
		else
		{
			Timer0_control = 0b00000101;	// Timer0, normal mode, /1024 pre-scalar
			Timer0_data = (int)CyclesToOverFlowOneByte - (int)((int)time / (int)preScaler); 
			while(Timer0_overflow_flag == 0);
			Timer_flags = 0x01;  		// Clear TOV0 flag
			Timer0_control = 0x00; // disable timer0
		}
		
		
	}
}
