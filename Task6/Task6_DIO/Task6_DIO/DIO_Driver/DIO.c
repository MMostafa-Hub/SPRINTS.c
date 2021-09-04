/*
 * DIO.c
 *
 * Created: 4/9/2021 9:03:17 PM
 *  Author: OWNER
 */ 
#include "registers.h"
//#include <avr/io.h>
void DIO_init_PortC()
{
	PORTC_DIR = 0x00; // input for the button 
}
void DIO_init_PortA()
{
	PORTA_DIR = 0x01; // output for the led
}
int DIO_read_portC()
{
	return PINC_Data; // return the input data from the button
}
void DIO_write_PortA(int value)
{
	PORTA_Data = value;
}