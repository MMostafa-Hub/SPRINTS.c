/*
* Task 5 USART Driver.c
*
* Created: 26/9/2021 11:54:49 AM
* Author : OWNER
*/

#include <avr/io.h>
#include <avr/delay.h>
#define F_CPU 16000000UL
#define	BAUD 9600
#define FOSC 16000000
#define	BAUD_RATE FOSC/16/BAUD-1
void USART_Init( uint16_t baud )
{
	/* Set baud rate */
	UBRRH = (uint8_t)(baud>>8);
	UBRRL = (uint8_t)baud;
	/* Enable receiver and transmitter */
	UCSRB = (1<<RXEN)|(1<<TXEN);
	/* Set frame format: 8data, 2stop bit */
	UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
}
void USART_Transmit( uint8_t data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) );
	/* Put data into buffer, sends the data */
	UDR = data;
}
uint8_t USART_Receive( void )
{
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) );
	/* Get and return received data from buffer */
	return UDR;
}
void UART_SendString(char *str)
{
	unsigned char j=0;
	
	while (str[j]!=0)		/* Send string till null */
	{
		USART_Transmit(str[j]);
		j++;
	}
}


int main(void)
{
	/* Replace with your application code */
	USART_Init(BAUD_RATE);
	
	while (1)
	{
			UART_SendString("DUCK");

	}
}

