/*
 * macros.h
 *
 * Created: 15/9/2021 12:55:27 PM
 *  Author: OWNER
 */ 


#ifndef MACROS_H_
#define MACROS_H_

#include <stdlib.h>
#include <avr/io.h>
#include <math.h>
#include <avr/interrupt.h>
//#include <avr/delay.h>

//#define F_CPU 160000000UL
#define INPUT 0
#define OUTPUT 1
#define ON 1
#define OFF 0
#define True 1
#define MaxNumber8bit 255

typedef volatile uint8_t  vuint8_t;
#define mem(x) (*(vuint8_t*)(x))
#define itoc(x) x+'0'

#define lcd_data mem(0x32)
#define lcd_control mem(0x35)

#define RS 0
#define RW 1
#define EN 2
#define D0 0
#define D1 1
#define D2 2
#define D3 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7

#define PORTA_Dir mem(0x3A)
#define PORTA_Data mem(0x3B)
#define PORTA_Pin mem(0x39)

#define PORTB_Dir mem(0x37)
#define PORTB_Data mem(0x38)
#define PORTB_Pin mem(0x36)

#define PORTC_DIR mem(0x34)
#define PINC_Data mem(0x33)

#define red_led 0
#define yellow_led 1

#define Timer0_control mem(0x53)
#define Timer0_data mem(0x52)
#define Timer_flags mem(0x58)
#define Timer0_overflow_flag (Timer_flags & 0x01)

#define btn 2

#define Timer1_control_regA mem(0x4f)
#define Timer1_control_regB mem(0x4e)
#define Timer1_interr_mask mem(0x59)
#define Timer1_overflow_flag (Timer_flags & (1<<2))



#endif /* MACROS_H_ */
