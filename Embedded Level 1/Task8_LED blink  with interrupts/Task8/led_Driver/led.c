/*
* led.c
*
* Created: 4/9/2021 9:35:24 PM
*  Author: OWNER
*/
#include "../DIO_Driver/DIO.h"
#include "../Timer_Driver/timer.h"
#include "../registers.h"


#define ON 1
#define OFF 0
void led_init(void)
{
	DIO_init(PORTA_DIR_addr,0x01);
}

void led_write(int value)
{
	DIO_write(PORTA_Data_addr,(value>=1));
}

void led_blink(int time)
{
	led_write(ON);
	timer_delay(time);
	led_write(OFF);
	timer_delay(time);

}


void led_blink_interr(int time)
{
	timer_interr_delay(time);
}
