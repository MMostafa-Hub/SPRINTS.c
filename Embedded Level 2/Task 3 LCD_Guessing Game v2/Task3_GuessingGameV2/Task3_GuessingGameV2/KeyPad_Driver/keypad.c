/*
 * keypad.c
 *
 * Created: 29/9/2021 5:19:23 PM
 *  Author: OWNER
 */ 
#include "../macros.h"
uint8_t keypad(void)
{
	PORTA = 0x10; // portA4 is HIGH
	if((PINA & (1<<PORTA0))) { return '7';}
	else if((PINA & (1<<PORTA1))) { return '8';}
	else if((PINA & (1<<PORTA2))) { return '9';}
	else if((PINA & (1<<PORTA3))) { return invalid;}
	
	timer_delay(1);
	PORTA = 0x20; // portA5 is HIGH
	if((PINA & (1<<PORTA0))){ return '4';}
	else if((PINA & (1<<PORTA1))) { return '5';}
	else if((PINA & (1<<PORTA2))) { return '6';}
	else if((PINA & (1<<PORTA3))) { return invalid;}
	
	timer_delay(1);
	PORTA = 0x40; // portA6 is HIGH
	if((PINA & (1<<PORTA0))) { return '1';}
	else if((PINA & (1<<PORTA1))) { return '2';}
	else if((PINA & (1<<PORTA2))) { return '3';}
	else if((PINA & (1<<PORTA3))) { return invalid;}
	timer_delay(1);

	PORTA = 0x80; // portA7 is HIGH
	if((PINA & (1<<PORTA0))) { return invalid;}
	else if((PINA & (1<<PORTA1))) { return '0';}
	else if((PINA & (1<<PORTA2))) { return ENTER;}
	else if((PINA & (1<<PORTA3))) { return invalid;}
	timer_delay(1);
	
	return none;
}