/*
 * DIO.c
 *
 * Created: 4/9/2021 9:03:17 PM
 *  Author: OWNER
 */ 
#include "../registers.h"

void DIO_init(int DRR_address ,int direction)
{
	mem(DRR_address) = direction;
}
int DIo_read(int PIN_address)
{
	return mem(PIN_address);
}
void DIO_write(int PORT_address, int value)
{
	mem(PORT_address) = value;
}