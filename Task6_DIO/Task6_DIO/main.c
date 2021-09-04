/*
* Task6_DIO.c
*
* Created: 4/9/2021 8:57:17 PM
* Author : OWNER
*/

 //#include <avr/io.h>
#define true 1
#include "Button_driver/button.h"
#include "LED_Driver/led.h"


int main(void)
{
	led_init();
	button_init();
	while (true)
	{
		if(button_pressed())
		{
			led_ON();
		}
		else
		{
			led_OFF();
		}
	}
}