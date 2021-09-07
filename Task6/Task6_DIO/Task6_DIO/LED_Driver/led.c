/*
 * led.c
 *
 * Created: 4/9/2021 9:35:24 PM
 *  Author: OWNER
 */ 
#include "../DIO_Driver/DIO.h"
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