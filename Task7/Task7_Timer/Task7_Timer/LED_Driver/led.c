/*
 * led.c
 *
 * Created: 4/9/2021 9:35:24 PM
 *  Author: OWNER
 */ 
#include "../DIO_Driver/DIO.h"
#include "../Timer_Driver/timer.h"
#include "../registers.h"

//#include <avr/io.h>
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
	led_write(1);
	timer_init(time);
	led_write(0);
	timer_init(time);

}


