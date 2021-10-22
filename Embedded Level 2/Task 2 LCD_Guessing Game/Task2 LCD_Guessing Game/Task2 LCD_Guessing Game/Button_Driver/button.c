/*
 * button.c
 *
 * Created: 11/10/2021 6:53:52 PM
 *  Author: OWNER
 */ 
#include "../macros.h"
#include "../DIO_Driver/dio.h"
#include "../Led_Driver/led.h"
#include "../Timer_Driver/timer.h"

void button_init(vuint8_t* PORT_, vuint8_t* DDR_, uint8_t bitNumber)
{
	DIO_init(PORT_,DDR_,INPUT,bitNumber);
}

uint8_t button_pressed(vuint8_t* PIN_, uint8_t bitNumber)
{
	return DIO_read(PIN_,bitNumber);
}