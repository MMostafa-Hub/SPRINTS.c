/*
 * keypad.h
 *
 * Created: 18/9/2021 11:09:39 AM
 *  Author: OWNER
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_



u8 keypad(void)
{
	PORTA = 0x10;
	if((PINA & (1<<PORTA0))) { return '7';}
	else if((PINA & (1<<PORTA1))) { return '8';}
	else if((PINA & (1<<PORTA2))) { return '9';}
	else if((PINA & (1<<PORTA3))) { return invalid;}
	
	timer_delay(1);
	PORTA = 0x20;
	if((PINA & (1<<PORTA0))){ return '4';}
	else if((PINA & (1<<PORTA1))) { return '5';}
	else if((PINA & (1<<PORTA2))) { return '6';}
	else if((PINA & (1<<PORTA3))) { return invalid;}
	
	timer_delay(1);
	PORTA = 0x40;
	if((PINA & (1<<PORTA0))) { return '1';}
	else if((PINA & (1<<PORTA1))) { return '2';}
	else if((PINA & (1<<PORTA2))) { return '3';}
	else if((PINA & (1<<PORTA3))) { return invalid;}
	timer_delay(1);

	PORTA = 0x80;
	if((PINA & (1<<PORTA0))) { return invalid;}
	else if((PINA & (1<<PORTA1))) { return '0';}
	else if((PINA & (1<<PORTA2))) { return '=';}
	else if((PINA & (1<<PORTA3))) { return invalid;}
	timer_delay(1);
	
	return none;
}

#endif /* KEYPAD_H_ */