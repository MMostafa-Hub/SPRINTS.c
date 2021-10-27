/*
 * app.c
 *
 * Created: 26/10/2021 10:24:14 PM
 *  Author: OWNER
 */ 
#include "app.h"
void app_init(void)
{
	/* Initialize the SPI driver as Slave */
	SPI_initSlave();
	
	DIO_setupPortDirection(PORTC_ID,PORT_OUTPUT); /* All PORTC pins are o/p pins */
	DIO_writePort(PORTC_ID,0x00); /* Turn OFF all LEDS */
	

}