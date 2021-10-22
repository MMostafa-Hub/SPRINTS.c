#include "USART/uart.h"

#define MAX_SIZE 100

int main(void)
{
	USART_Init(9600);
	uint8 c[MAX_SIZE] = "" ;
	while(1)
	{
		USART_SendString((uint8*)"INPUT: ");
		USART_ReceiveString(c);
		USART_SendByte('\r');
		
		USART_SendString((uint8*)"ECHO : ");
		USART_SendString(c);
		USART_SendByte('\r');
		USART_SendByte('\r');
	}
}