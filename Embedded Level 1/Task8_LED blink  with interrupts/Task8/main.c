/*
 * Task8.c
 *
 * Created: 7/9/2021 12:51:13 PM
 * Author : OWNER
 */ 
#define True 1
#include "registers.h"
#include "led_Driver/led.h"
#include "Timer_Driver/timer.h"


inline void app_init(void)
{
	led_init();
	timer_interr_init();
}

// TASK 8 : Interrupts
int main(void)
{
	app_init();
	led_blink_interr(300);

    while (True)
	{
	}		
   return 0;
}

