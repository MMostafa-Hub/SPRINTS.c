/*
 * led.c
 *
 * Created: 28/9/2021 9:27:14 PM
 *  Author: OWNER
 */ 

#include "../DIO_Driver/dio.h"
#include "../Timer_Driver/timer.h"
#include "../macros.h"



void led_init(vuint8_t* PORT_, vuint8_t* DDR_, int8_t bitNumber)
{
	DIO_init(PORT_,DDR_,OUTPUT,bitNumber);
}

void led_write(vuint8_t* PORT_, int8_t bitNumber, int8_t value)
{
	DIO_write(PORT_,bitNumber,value);
}

void led_blink(vuint8_t* PORT_, int8_t bitNumber,uint16_t time)
{
	led_write(PORT_,bitNumber, ON);
	timer_delay(time);
	led_write(PORT_,bitNumber,OFF);
	timer_delay(time);
}
