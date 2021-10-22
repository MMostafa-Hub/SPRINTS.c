/*
 * led.c
 *
 * Created: 11/10/2021 6:56:23 PM
 *  Author: OWNER
 */ 
#include "led.h"

void led_init(vuint8_t* PORT_, vuint8_t* DDR_, int8_t bitNumber)
{
	DIO_init(PORT_,DDR_,OUTPUT,bitNumber);
}

void led_write(vuint8_t* PORT_, int8_t bitNumber, int8_t value)
{
	DIO_write(PORT_,bitNumber,value);
}
