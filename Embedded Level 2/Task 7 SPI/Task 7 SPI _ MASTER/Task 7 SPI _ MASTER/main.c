/*
 * main.c
 *
 * Created: 26/10/2021 10:30:22 PM
 *  Author: OWNER
 */ 
#include "app.h"
#define MAX_SIZE 255
int main(void)
{
	app_init();
	USART_SendString((uint8*)"MASTER\r");

	/* Send the string to MC2 */
	uint8 message[MAX_SIZE];

    while(1)
    {
		USART_ReceiveString(message);
		
		SPI_sendString(message);
		SPI_sendReceiveByte('\r');
		
    }
}


