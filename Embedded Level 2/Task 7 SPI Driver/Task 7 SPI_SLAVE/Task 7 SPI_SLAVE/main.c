/*
 * Task 7 SPI_SLAVE.c
 *
 * Created: 22/10/2021 8:28:35 PM
 * Author : OWNER
 */ 

#include <avr/io.h>
#include "USART/usart.h"
#include "SPI/spi.h"

void app_init(void)
{
	USART_Init(9600);
	SPI_InitSlave();	
	
}
int main(void)
{
    /* Replace with your application code */
	app_init();
	uint8 c[100];
    while (1) 
    {
		USART_SendString((uint8*)"SLAVE:\r");
		
		/* FORM MASTER */
		SPI_ReceiveString(c);
		
		/* TO TERMINAL */
		USART_SendString(c);
		
		USART_SendString((uint8*)"\r");

		
    }
}

