/*
 * button.c
 *
 * Created: 4/9/2021 9:37:26 PM
 *  Author: OWNER
 */ 
#include "../DIO_Driver/DIO.h"
#include "../registers.h"
 
void button_init(void)
{
	DIO_init(PORTC_DIR_addr,1);
}
int button_pressed(void)
{
	return (DIo_read(PINC_Data_addr) == 0x01);
}
