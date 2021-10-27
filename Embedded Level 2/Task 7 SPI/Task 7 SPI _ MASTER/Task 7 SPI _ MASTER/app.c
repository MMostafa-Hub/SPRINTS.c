/*
 * app.c
 *
 * Created: 27/10/2021 5:50:15 PM
 *  Author: OWNER
 */ 

#include "app.h"
void app_init()
{
	
	/* Initialize the SPI driver as Master */
	SPI_initMaster();
	/* Baud Rate = 9600 */
	USART_Init(BAUD_RATE);
		
}