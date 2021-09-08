/*
 * CAR.c
 *
 * Created: 8/9/2021 2:51:48 PM
 * Author : OWNER
 */ 

#include <avr/io.h>

#define True 1
#define set(x) (1<<x)
void app_init()
{
	
}
int main(void)
{
	DDRC |= (1<<PORTC0) | (1<<PORTC1)| (1<<PORTC2) | (1<<PORTC3);
	// Right Motor
	PORTC |= (1<<PORTC0);	//in1 //high
	PORTC &= ~(1<<PORTC1);	// in2 //low  Then Forward CLock Wise
	// Left Motor
	PORTC |= (1<<PORTC3);	// in3 // high 
	PORTC &= ~(1<<PORTC4);	// in4 // low Then Forward CLock Wise
	
	
	// Controlling the speed of the motors using Fast PWM , Timer0, 1/128 preScaler
	DDRB |= set(PORTB3);
	TCCR0 |= set(WGM01) | set(WGM00) | set(COM01) | set(CS00) | set(CS02);
	TCCR0 &= ~set(COM00) | ~set(CS01);
	OCR0 = 200; // 10/256 * 100 % of full speed
	
    while (True) 
    {
		
    }
}

