/*
 * main.c
 *
 * Created: 26/10/2021 10:24:25 PM
 *  Author: OWNER
 */ 
#include "app.h"

int main(void)
{

	app_init();
	uint8 recieved_data = ' ';
	
	recieved_data = SPI_sendReceiveByte(SPI_DEFAULT_DATA_VALUE);
	DIO_writePort(PORTC_ID,recieved_data);
	
    while(1)
    {
		
			
    }
}

