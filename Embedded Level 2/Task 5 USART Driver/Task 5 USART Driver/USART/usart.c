/*
 * usart.c
 *
 * Created: 15/10/2021 2:00:02 PM
 *  Author: OWNER
 */ 

#include "uart.h"

void USART_Init(uint32 baud_rate)
{
	/* *************** ********** USCRA Description ***********************
	*	U2X = 1 for double transmission speed 
	***********************************************************************/
	UCSRA |= (1<<U2X);
	
	/************************** UCSRB Description **************************
	 * RXCIE = 0 Disable USART RX Complete Interrupt Enable
	 * TXCIE = 0 Disable USART TX Complete Interrupt Enable
	 * UDRIE = 0 Disable USART Data Register Empty Interrupt Enable
	 * RXEN  = 1 Receiver Enable
	 * RXEN  = 1 Transmitter Enable
	 * UCSZ2 = 0 For 8-bit data mode
	 * RXB8 & TXB8 not used for 8-bit data mode
	 ***********************************************************************/ 
	UCSRB |= (1<<RXEN) | (1<<TXEN);
	
	/************************** UCSRC Description **************************
	 * URSEL   = 1 The URSEL must be one when writing the UCSRC
	 * UMSEL   = 0 Asynchronous Operation
	 * UPM1:0  = 00 Disable parity bit
	 * USBS    = 0 One stop bit
	 * UCSZ1:0 = 11 For 8-bit data mode
	 * UCPOL   = 0 Used with the Synchronous operation only
	 ***********************************************************************/
	UCSRC |= (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1);
	
	/* Calculate the UBRR register value */
	uint16 ubrr_value = (uint16)(((F_CPU / (baud_rate * 8UL))) - 1);
	
	/* First 8 bits from the BAUD_PRESCALE inside UBRRL and last 4 bits in UBRRH*/
	UBRRH = ubrr_value>>8; // hihger 8-bits
	UBRRL = ubrr_value; // lower 8-bits
}

/*
*	Description: sends a character(BYTE) to another USART device
*	Input args: the character that the user wants to send 
*/
void USART_SendByte(uint8 data)
{
	/* Waits for the data register to be empty */
	while(BIT_IS_CLEAR(UCSRA,UDRE));
	UDR = data;
}

/*
*	Description: Receives a character (BYTE) from another USART device
*/
uint8 USART_ReceiveByte()
{
	/* Waits until the receive is completed */
	while(BIT_IS_CLEAR(UCSRA,RXC));
	return UDR;
}

/*
*	Description: sends a string to another USART device
*	Input args: the reference of the string that the user wants to send
*/
void USART_SendString(uint8 *str)
{
	while(*str != '\0')
	{
		USART_SendByte(*str);
		str++;
	}
}

/*
*	Description: Receives a string from another USART device
*	Input args: the reference of the string that the user wants to save the received data into
*/
void USART_ReceiveString(uint8 *str)
{
	uint8 i = 0;
	str[i] = USART_ReceiveByte();
	/* '\r' new line character */
	while(str[i] != '\r') 
	{
		i++;
		str[i] = USART_ReceiveByte();
	}
	str[i] = '\0';
}