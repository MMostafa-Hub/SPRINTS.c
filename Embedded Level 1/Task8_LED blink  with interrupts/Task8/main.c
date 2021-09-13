/*
 * Task8.c
 *
 * Created: 7/9/2021 12:51:13 PM
 * Author : OWNER
 */ 
#define true 1
#include "registers.h"
#include "led_Driver/led.h"


// TASK 8 : Interrupts
int main(void)
{
	led_init();
	led_blink_interr(1000);

    while (true)
	{
	}		
   return 0;
}

