/*
 * registers.h
 *
 * Created: 10/9/2021 11:26:04 AM
 *  Author: OWNER
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

#include <stdint.h>
#include <math.h>

typedef volatile uint8_t  vuint8_t;
#define mem(x) (*(vuint8_t*)(x))
#define True 1

#define INPUT 0
#define OUTPUT 1
#define ON 1
#define OFF 0
#define MaxNumber8bit 255

#define  buttonL 0
#define  buttonM 1
#define  buttonR 2
#define  buttonG 3

#define motor1_IN1 0
#define motor1_IN2 1
#define motor2_IN1 2
#define motor2_IN2 3

#define PORTA_Data mem(0x3B)
#define PORTA_Dir mem(0x3A)
#define PORTA_Pin mem(0x39)

#define PORTC_Data mem(0x35)
#define PORTC_Dir mem(0x34)
#define PORTC_Pin mem(0x33)

#define PORTB_Data mem(0x38)
#define PORTB_Dir mem(0x37)
#define PORTB_Pin mem(0x36)

#define Timer0_control mem(0x53)
#define Timer0_Compare mem(0x5C)


#define Timer0_control mem(0x53)
#define Timer0_data mem(0x52)
#define Timer0_flags mem(0x58)
#define Timer0_overflow_flag (Timer0_flags & 0x01)

#define CyclesToOverFlowNormal 255
#define preScaler 1.024

#endif /* REGISTERS_H_ */