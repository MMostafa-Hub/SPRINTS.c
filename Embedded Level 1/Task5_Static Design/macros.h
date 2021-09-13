#ifndef REGISTERS_H_
#define REGISTERS_H_

#include <stdint.h>
typedef volatile uint8_t  vuint8_t;
#define mem(x) (*(vuint8_t*)(x))

#define INPUT 0
#define OUTPUT 1
#define ON 1
#define OFF 0

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

#endif /* REGISTERS_H_ */