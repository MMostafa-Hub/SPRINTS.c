
#include "app.h"

int main(void)
{
	
	app_init();
	
	uint8 write_data = 0;
	uint8 read_data = 0;
	uint16 eeprom_mem_address;
	
	uint8 s_eeprom_mem_address[MEM_ADDRESS_SIZE];
	
	uint8 command[5];
	memset(command,'\0',5);

	
	
	while(1)
	{
		USART_SendString((uint8*)"PLEASE ENTER YOUR COMMAND:\r");
		USART_ReceiveString(command);
		
		if(!strcmp(command,"WRITE"))
		{
			memset(s_eeprom_mem_address,'0',MEM_ADDRESS_SIZE);
			USART_SendString((uint8*)"PLEASE ENTER THE ADDRESS:\r");
			
			/* receives the address from terminal */
			USART_ReceiveString(s_eeprom_mem_address);
			
			
			/* converting the address from string into integer */
			eeprom_mem_address = string_to_binary_to_decimal(s_eeprom_mem_address,MEM_ADDRESS_SIZE);
			itoa(eeprom_mem_address ,(char *)s_eeprom_mem_address,10);
			
			
			USART_SendString((uint8*)"OK");
			USART_SendByte('\r');
			
			
			USART_SendString((uint8*)"PLEASE ENTER THE DATA:\r");
			
			/* receive data from the user (Terminal) */
			write_data = USART_ReceiveByte();
			USART_SendByte('\r');
			
			/* Write the input data in the external EEPROM */
			EEPROM_writeByte(eeprom_mem_address, write_data);
			
			
			USART_SendString((uint8*)"OK");
			USART_SendByte('\r');
			
		}else if (!strcmp(command,"READ"))
		{
			memset(s_eeprom_mem_address,'0',MEM_ADDRESS_SIZE);
			USART_SendString((uint8*)"PLEASE ENTER THE ADDRESS:\r");
			
			/* receives the address from terminal */
			USART_ReceiveString(s_eeprom_mem_address);
			
			/* converting the address from string into integer */
			eeprom_mem_address = string_to_binary_to_decimal(s_eeprom_mem_address,MEM_ADDRESS_SIZE);
			itoa(eeprom_mem_address ,(char *)s_eeprom_mem_address,10);
			
			
			USART_SendString((uint8*)"OK");
			USART_SendByte('\r');
			
			/* Read eeprom_mem_address from the external EEPROM */
			EEPROM_readByte(eeprom_mem_address, &read_data);
			USART_SendString((uint8*)"data from EEPROM......\r");
			
			/* Writing the data in the EEPROM  on the terminal */
			USART_SendString((uint8*)"THE DATA IS:");
			USART_SendByte(read_data);
			USART_SendByte('\r');
			
			/* out the read value from the external EEPROM on LEDS*/
			DIO_writePort(PORTA_ID,read_data);
		}
	}
	return 0;
}
