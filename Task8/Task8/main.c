/*
 * Task8.c
 *
 * Created: 7/9/2021 12:51:13 PM
 * Author : OWNER
 */ 
#define true 1
#include "registers.h"
#include "led_Driver/led.h"
#include "Timer_Driver/timer.h"
//#include <avr/interrupt.h>


int main(void)
{
	led_init();
	timer_init_interr(1000);

    while (true)
	{
	//	led_blink(1000);
		}		
   return 0;
}

