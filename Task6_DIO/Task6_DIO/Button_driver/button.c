/*
 * button.c
 *
 * Created: 4/9/2021 9:37:26 PM
 *  Author: OWNER
 */ 
#include "../DIO_Driver/DIO.h"


void button_init(void)
{
	DIO_init_PortC();
}
int button_pressed(void)
{
	return (DIO_read_portC() == 0x01);
}
