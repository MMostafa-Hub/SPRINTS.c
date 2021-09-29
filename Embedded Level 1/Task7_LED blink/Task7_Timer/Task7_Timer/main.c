/*
* Task6_DIO.c
*
* Created: 4/9/2021 8:57:17 PM
* Author : OWNER
*/

#define True 1
#include "LED_Driver/led.h"
#include "Timer_Driver/timer.h"
inline void app_init(void)
{
	led_init();
	timer_init();
}


int main(void)
{
	app_init();
	while (True)
	{
		led_blink(1);
	}
}
