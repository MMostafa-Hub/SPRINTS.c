/*
* motor.h
*
* Created: 8/9/2021 6:00:48 PM
*  Author: OWNER
*/


#ifndef MOTOR_H_
#define MOTOR_H_
#include "../macros.h"
#include "../DIO_Driver/dio.h"
#include "../Timer_Driver/timer.h"
#include <math.h>

void motor_init(vuint8_t* PORT_IN1,vuint8_t* PORT_IN2,vuint8_t* IN1_DDR, vuint8_t* IN2_DDR,uint8_t IN1_bitNumber , uint8_t IN2_bitNumber)
{
	DIO_init(PORT_IN1,IN1_DDR,OUTPUT,IN1_bitNumber);
	DIO_init(PORT_IN2,IN2_DDR,OUTPUT,IN2_bitNumber);
}

void move_forward(vuint8_t* PORT_IN1,vuint8_t* PORT_IN2,uint8_t IN1_bitNumber , uint8_t IN2_bitNumber)
{
	*PORT_IN1 |= (1<<IN1_bitNumber);	//in1 //high
	*PORT_IN2 &= ~(1<<IN2_bitNumber);	// in2 //low  Then Forward CLock Wise
}

void stop(vuint8_t* PORT_IN1,vuint8_t* PORT_IN2,uint8_t IN1_bitNumber , uint8_t IN2_bitNumber)
{
	*PORT_IN1 &= ~(1<<IN1_bitNumber);	//in1 //high
	*PORT_IN2 &= ~(1<<IN2_bitNumber);
}

void move_backwards(vuint8_t* PORT_IN1,vuint8_t* PORT_IN2,uint8_t IN1_bitNumber , uint8_t IN2_bitNumber)
{
	*PORT_IN1 &= ~(1<<IN1_bitNumber);	//in1 //high
	*PORT_IN2 |= (1<<IN2_bitNumber);	// in2 //low  Then Forward CLock Wise
}

void set_speed(uint8_t percentage)
{
	uint8_t speed = ceil(((double)((double)percentage/(double)100))*(double)255);
	if(percentage <= 100)
		Fast_PWM(speed);
}


#endif /* MOTOR_H_ */