/*
 * button.h
 *
 * Created: 16/9/2021 3:00:49 PM
 *  Author: OWNER
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_


#include "../DIO_Driver/dio.h"
#include "../registers.h"

void button_init(void)
{
	DIO_init(PORTC_DIR_addr,0x00);
}
int button_pressed(void)
{
	return (DIO_read(PINC_Data_addr) == 0x01);
}



#endif /* BUTTON_H_ */