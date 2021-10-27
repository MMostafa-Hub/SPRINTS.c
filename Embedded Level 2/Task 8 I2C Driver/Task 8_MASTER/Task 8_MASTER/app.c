/*
 * app.c
 *
 * Created: 25/10/2021 8:38:23 PM
 *  Author: OWNER
 */ 

#include "app.h"
void app_init(void)
{
	/* Initialize the TWI/I2C Driver */
	TWI_init();
	
	DIO_setupPortDirection(PORTA_ID,PORT_OUTPUT); /* All PORTA pins are o/p pins */
	DIO_writePort(PORTA_ID,0x00); /* Turn OFF all LEDS */
	
	USART_Init(9600);
	
}
uint16 power(uint8 num, uint8 p)
{
	uint16 powerrr = 1;
	for ( int i = 0 ; i < p ; i++)
	{
		powerrr = powerrr * 2;
	}
	return powerrr;
}
uint16 string_to_binary_to_decimal(uint8 s_eeprom_mem_address[], uint8 size)
{
	uint16 decimal_value = 0;
	
	for(int i = 0; i < size; i++)
	{
		if(s_eeprom_mem_address[i] == '1')
		{
			decimal_value += power(2, size - 1 - i);
		}

	}
	return decimal_value;
	
}