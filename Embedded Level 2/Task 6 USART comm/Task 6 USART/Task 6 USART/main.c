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
		*	returns 1 if str1 > str2
		*	returns -1 if str1 < str2
		*/		
		if(!strcmp(s_input,"START"))
		{
			led_write(&PORTA,GREEN_LED,ON); // GREEN
			led_write(&PORTA,YELLOW_LED,OFF); // YELLOW
			led_write(&PORTA,RED_LED,OFF); // RED
			USART_SendString((uint8*)"Green LED is ON \r");
		}
		else if(!strcmp(s_input,"WAIT"))
		{
			led_write(&PORTA,GREEN_LED,OFF); // GREEN
			led_write(&PORTA,YELLOW_LED,ON); // YELLOW
			led_write(&PORTA,RED_LED,OFF); // RED	
			USART_SendString((uint8*)"Yellow LED is ON \r");
		}
		else if(!strcmp(s_input,"STOP"))
		{	
			led_write(&PORTA,GREEN_LED,OFF); // GREEN
			led_write(&PORTA,YELLOW_LED,OFF); // YELLOW
			led_write(&PORTA,RED_LED,ON); // RED
			USART_SendString((uint8*)"RED LED is ON \r");
		}
		else if (!strcmp(s_input,"AT"))
		{
			USART_SendString((uint8*)"OK\r");
		}

	}
}

