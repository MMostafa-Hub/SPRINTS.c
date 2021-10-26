#include "USART/uart.h"

#define MAX_SIZE 100
#define BAUD_RATE 9600
int main(void)
{
	USART_Init(BAUD_RATE);
	uint8 str[MAX_SIZE] = "" ;
	while(1)
	{
		USART_SendString((uint8*)"INPUT: ");
		USART_ReceiveString(str);
		USART_SendByte('\r');
		
		USART_SendString((uint8*)"ECHO : ");
		USART_SendString(str);
		USART_SendByte('\r');
		USART_SendByte('\r');
	}
}