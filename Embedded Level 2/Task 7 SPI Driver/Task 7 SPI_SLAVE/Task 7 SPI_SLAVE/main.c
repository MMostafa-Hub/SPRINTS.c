/*
 ================================================================================================
 Name        : MC2.c
 Author      : Mohamed Tarek
 Description : MC2 Code in Exercise2
 Date        : 4/11/2014
 ================================================================================================
 */

#include "SPI/spi.h"
#include "USART/usart.h"
#include <util/delay.h>
#include <string.h>
#define MC2_READY 0x10

int main(void)
{
	uint8 str[256];

// 	/* Initialize the LCD Driver */
// 	LCD_init();
	/* Initializing USART */
	USART_Init(9600);
	/* Initialize the SPI driver as Slave */
	SPI_initSlave();
	
	USART_SendString((uint8*)"SLAVE\r");
	
// 	/* Display the received string on the LCD display */
// 	LCD_displayString(str);

    while(1)
    {
			/* Receive String from MC1 */
			SPI_receiveString(str);
			
			/* Sending string form MC1 to terminal */
			USART_SendString(str);
			USART_SendByte('\r');
			memset(str,'\0',256);
			_delay_ms(100);
			
    }
}

