/*
* Task6_DIO.c
*
* Created: 4/9/2021 8:57:17 PM
* Author : OWNER
*/

#define true 1
#include "LED_Driver/led.h"

inline void app_init(void)
{
	led_init();
}

int main(void)
{
	app_init();
	while (true)
	{
		led_blink(300);
	}
}
