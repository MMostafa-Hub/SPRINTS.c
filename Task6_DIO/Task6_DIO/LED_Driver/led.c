/*
 * led.c
 *
 * Created: 4/9/2021 9:35:24 PM
 *  Author: OWNER
 */ 
#include "../DIO_Driver/DIO.h"

void led_init(void)
{
	DIO_init_PortA();
}

void led_ON(void)
{
	DIO_write_PortA(0x01);	
}

void led_OFF(void)
{
	DIO_write_PortA(0x00);
}