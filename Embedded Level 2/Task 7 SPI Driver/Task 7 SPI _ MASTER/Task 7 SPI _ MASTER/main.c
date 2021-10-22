/*
* Task 7 SPI _ MASTER.c
*
* Created: 22/10/2021 8:27:01 PM
* Author : OWNER
*/

#include <avr/io.h>
#include "SPI/spi.h"
#include "USART/usart.h"
void app_init(void)
{
	USART_Init(9600);
	SPI_InitMaster();
}
int main(void)
{
	/* Replace with your application code */
	app_init();
	uint8 c[100];
	while (1)
	{
		USART_SendString((uint8*)"MASTER:\r");
		
		/* FROM TERMINAL */
		USART_ReceiveString(c);
		/* TO SLAVE */
		SPI_SendString(c);
		
		/* ECHOOOOO */
		USART_SendString(c);
		USART_SendString((uint8*)"\r");
	}
}

