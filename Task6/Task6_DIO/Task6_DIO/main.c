/*
* Task6_DIO.c
*
* Created: 4/9/2021 8:57:17 PM
* Author : OWNER
*/

#define true 1
#include "Button_driver/button.h"
#include "LED_Driver/led.h"

void app_init(void)
{
	led_init();
	button_init();
}

int main(void)
{
	app_init();	
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