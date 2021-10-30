/*
 * Task 8 _ SLAVE.c
 *
 * Created: 28/10/2021 11:32:11 PM
 * Author : OWNER
 */ 

#include <avr/io.h>
#include "app.h"

int main(void)
{
    /* Replace with your application code */
	TWI_init();
	uint8 x = TWI_readByteWithACK();
	
	
	
	DIO_setupPortDirection(PORTA_ID,PORT_OUTPUT);
	DIO_writePort(PORTA_ID,x);
    while (1) 
    {
    }
}

