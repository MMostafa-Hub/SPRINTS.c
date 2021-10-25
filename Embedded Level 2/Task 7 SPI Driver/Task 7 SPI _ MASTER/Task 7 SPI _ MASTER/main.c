/*
 ================================================================================================
 Name        : MC1.c
 Author      : Mohamed Tarek
 Description : MC1 Code in Exercise2
 Date        : 4/11/2014
 ================================================================================================
 */

#include "SPI/spi.h"
#include "USART/usart.h"
#include <string.h>
#include <util/delay.h> /* To use the delay functions */

int main(void)
{
	/* Initialize the SPI driver as Master */
	SPI_initMaster();
	USART_Init(9600);
	/* Delay until MC2 finish its initialization task */
	_delay_ms(100);

	USART_SendString((uint8*)"MASTER\r");

	/* Send the string to MC2 */
	/*SPI_sendString((uint8*)"I am Micro1\r");*/
	uint8 message[256];

    while(1)
    {
		USART_ReceiveString(message);
		//SPI_sendString((uint8*)"message\r");
		SPI_sendString(message);
		SPI_sendReceiveByte('\r');
		memset(message,'\0',256);

		_delay_ms(100);
		
    }
}


