/*
* Task6_DIO.c
*
* Created: 4/9/2021 8:57:17 PM
* Author : OWNER
*/


#include "Button_driver/button.h"
#include "LED_Driver/led.h"
#define True 1
#define ON 1
#define OFF 0


void app_init(void)
{
	led_init();
	button_init();
}

int main(void)
{
	app_init();	
	while (True)
	{
		if(button_pressed())
		{
			led_write(ON);
		}
		else
		{
			led_write(OFF);
		}
	}
}