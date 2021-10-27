/*
 * app.c
 *
 * Created: 26/10/2021 10:24:14 PM
 *  Author: OWNER
 */ 
#include "app.h"
void app_init(void)
{
	/* Initializing USART */
	/* Baud Rate = 9600 */

	USART_Init(BAUD_RATE);
	/* Initialize the SPI driver as Slave */
	SPI_initSlave();
	
}