/*
 * usart.c
 *
 * Created: 15/10/2021 2:00:02 PM
 *  Author: OWNER
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../std_types.h"
#include "../common_macros.h"
#include <avr/io.h> 


#define NUM_OF_PORTS           4
#define NUM_OF_PINS_PER_PORT   8

#define PORTA_ID               0
#define PORTB_ID               1
#define PORTC_ID               2
#define PORTD_ID               3

#define PIN0_ID                0
#define PIN1_ID                1
#define PIN2_ID                2
#define PIN3_ID                3
#define PIN4_ID                4
#define PIN5_ID                5
#define PIN6_ID                6
#define PIN7_ID                7


typedef enum
{
	PIN_INPUT,PIN_OUTPUT
}DIO_PinDirectionType;

typedef enum
{
	PORT_INPUT,PORT_OUTPUT=0xFF
}DIO_PortDirectionType;

void DIO_setupPinDirection(uint8 port_num, uint8 pin_num, DIO_PinDirectionType direction);
void DIO_writePin(uint8 port_num, uint8 pin_num, uint8 value);
uint8 DIO_readPin(uint8 port_num, uint8 pin_num);
void DIO_setupPortDirection(uint8 port_num, uint8 direction);
void DIO_writePort(uint8 port_num, uint8 value);
uint8 DIO_readPort(uint8 port_num);

#endif /* DIO_H_ */
