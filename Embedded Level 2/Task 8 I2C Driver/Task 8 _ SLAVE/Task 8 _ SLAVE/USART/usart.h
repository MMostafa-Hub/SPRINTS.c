/*
 * uart.h
 *
 * Created: 15/10/2021 2:00:18 PM
 *  Author: OWNER
 */ 


#ifndef USART_H_
#define USART_H_

#include "../std_types.h"
#include "../common_macros.h"
#include <avr/io.h>
#include <stdint.h>
#define F_CPU 1000000UL


void USART_Init(uint32 baud_rate);
void USART_SendByte(uint8 data);
uint8 USART_ReceiveByte();
void USART_SendString(uint8 *str);
void USART_ReceiveString(uint8 *str);



#endif /* USART_H_ */