/*
 * SPI.c
 *
 *  Created on: Jan 14, 2018
 *      Author: Mohamed
 */

#include "spi.h"

void SPI_InitMaster()
{
	DDRB |= (1<<PORTB4)|(1<<PORTB5)|(1<<PORTB7);
	SPCR |= (1<<SPE)|(1<<MSTR);
}

void SPI_InitSlave()
{
	DDRB |= (1<<PORTB6);
	SPCR |= (1<<SPE);
}

void SPI_SendByte(uint8 data)
{
	SPDR = data;
	while(BIT_IS_CLEAR(SPSR,SPIF));
}

uint8 SPI_ReceiveByte()
{
	while(BIT_IS_CLEAR(SPSR,SPIF));
	return SPDR;
}

void SPI_SendString(uint8 *str)
{
	while(*str)
	{
		SPI_SendByte(*str);
		str++;
	}
}

void SPI_ReceiveString(uint8 *str)
{
	uint8 i = 0;
	str[i] = SPI_ReceiveByte();
	while(str[i] != '#')
	{
		i++;
		str[i] = SPI_ReceiveByte();
	}
	str[i] = '\0';
}