/*
 * main.c
 *
 * Created: 26/10/2021 10:24:25 PM
 *  Author: OWNER
 */ 
#include "app.h"

#define MAX_SIZE 255
int main(void)
{
	app_init();
	
	uint8 str[MAX_SIZE];

	USART_SendString((uint8*)"SLAVE\r");
	
    while(1)
    {
		/* Receive String from MC1 */
		SPI_receiveString(str);
			
		/* Sending string form MC1 to terminal */
		USART_SendString(str);
		USART_SendByte('\r');
		
    }
}

