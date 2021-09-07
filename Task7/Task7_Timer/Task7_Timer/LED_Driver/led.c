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

void led_ON(void)
{
	DIO_write(PORTA_Data_addr,0x01);
}

void led_OFF(void)
{
	DIO_write(PORTA_Data_addr,0x00);
}

void led_ON_delay(int time)
{
	led_ON();
	timer_init(time);
}
void led_OFF_delay(int time)
{
	led_OFF();
	timer_init(time);
}

void led_blink(int time)
{
	led_ON_delay(time);
	led_OFF_delay(time);
}