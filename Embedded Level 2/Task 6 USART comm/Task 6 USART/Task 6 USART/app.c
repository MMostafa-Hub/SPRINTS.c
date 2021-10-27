/*
 * app.c
 *
 * Created: 15/10/2021 2:32:03 PM
 *  Author: OWNER
 */ 
#include "app.h"
void app_init(void)
{
	led_init(&PORTA,&DDRA,PORTA0); // Red
	led_init(&PORTA,&DDRA,PORTA1); // Green
	led_init(&PORTA,&DDRA,PORTA2); // Yellow

	/* Baud Rate = 9600 */
	USART_Init(BAUD_RATE);
}