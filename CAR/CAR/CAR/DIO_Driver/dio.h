/*
 * dio.h
 *
 * Created: 8/9/2021 6:00:59 PM
 *  Author: OWNER
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../macros.h"
#include <stdint.h>


void DIO_init(vuint8_t* PORT_, vuint8_t* DDR_, uint8_t dircetion, uint8_t bitNumber)
{
	
	if(dircetion == INPUT)
	{
		SFIOR &= ~( 1 << PUD);
		*DDR_ &= ~(1 << bitNumber);
		*PORT_ |= (1 << bitNumber); // Pull up resistor
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

#endif /* DIO_H_ */