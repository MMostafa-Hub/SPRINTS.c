/*
* Task 6 USART.c
*
* Created: 15/10/2021 2:12:04 PM
* Author : OWNER
*/
#include "app.h"
int main(void)
{
	app_init();
	uint8 s_input[100];
	while (TRUE)
	{
		USART_SendString((uint8*)"Please Enter Your Command \r");
		
		USART_ReceiveString(s_input);
		/*
		*	strcmp(str1,str2)
		*	returns 0 if str1 == str2
		*	returns 1 if str > str2
		*	returns -1 if str1 < str2
		*/		
		if(strcmp(s_input,"START") == 0)
		{
			led_write(&PORTA,2,ON); // GREEN
			led_write(&PORTA,1,OFF); // YELLOW
			led_write(&PORTA,0,OFF); // RED
			USART_SendString((uint8*)"Green LED is ON \r");
		}
		else if(strcmp(s_input,"WAIT") == 0)
		{
			led_write(&PORTA,2,OFF); // GREEN
			led_write(&PORTA,1,ON); // YELLOW
			led_write(&PORTA,0,OFF); // RED	
			USART_SendString((uint8*)"Yellow LED is ON \r");
		}
		else if(strcmp(s_input,"STOP") == 0)
		{	
			led_write(&PORTA,2,OFF); // GREEN
			led_write(&PORTA,1,OFF); // YELLOW
			led_write(&PORTA,0,ON); // RED
			USART_SendString((uint8*)"RED LED is ON \r");
		}
		else if (strcmp(s_input,"AT") == 0)
		{
			USART_SendString((uint8*)"OK\r");
		}
		else 
		{
			USART_SendString((uint8*)"PLEASE ENTER THE COMMAND RIGHT IN THE FIRST TRY\r")	;
		}
	}
}

