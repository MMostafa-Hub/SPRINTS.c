/*
* button.h
*
* Created: 8/9/2021 6:00:35 PM
*  Author: OWNER
*/

#ifndef BUTTON_H_
#define BUTTON_H_

#include "../macros.h"
#include "../DIO_Driver/dio.h"
#include <stdint.h>

void button_init(vuint8_t* PORT_, vuint8_t* DDR_, uint8_t bitNumber)
{
	DIO_init(PORT_,DDR_,INPUT,bitNumber);
}

uint8_t button_pressed(vuint8_t* PIN_, uint8_t bitNumber)
{
	return DIO_read(PIN_,bitNumber);	
}


#endif /* BUTTON_H_ */