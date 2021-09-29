/*
 * dio.c
 *
 * Created: 29/9/2021 4:57:14 PM
 *  Author: OWNER
 */ 
#include "../macros.h"


void DIO_init(vuint8_t* PORT_, vuint8_t* DDR_, uint8_t dircetion, uint8_t bitNumber)
{
	
	if(dircetion == INPUT)
	{
		*DDR_ &= ~(1 << bitNumber);
	}
	else
	{
		*DDR_ |= (1 << bitNumber);
	}
}
uint8_t DIO_read (vuint8_t* PIN_, uint8_t bitNumber)
{
	return ((*PIN_ & (1 << bitNumber)) == (1 << bitNumber));
}
void DIO_write(vuint8_t* PORT_, uint8_t bitNumber, uint8_t value)
{
	if(value != 0)
	{
		*PORT_ |= (1<<bitNumber);
	}
	else
	{
		*PORT_ &= ~(1<<bitNumber);
	}
}