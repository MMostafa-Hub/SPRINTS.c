/*
 * led.h
 *
 * Created: 10/9/2021 1:32:08 PM
 *  Author: OWNER
 */ 


#ifndef LED_H_
#define LED_H_

#include "../DIO_Driver/dio.h"
#include "../Timer_Driver/timer.h"
#include "../macros.h"

#include <avr/io.h>
//#include <avr/io.h>


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
	_delay_ms(time);
	led_write(PORT_,bitNumber,OFF);
	_delay_ms(time);
}



#endif /* LED_H_ */