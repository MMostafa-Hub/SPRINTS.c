/*
 * motor.c
 *
 * Created: 28/9/2021 9:28:03 PM
 *  Author: OWNER
 */ 
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
	*PORT_IN1 |= (1<<IN1_bitNumber);	//in1 HIGH
	*PORT_IN2 &= ~(1<<IN2_bitNumber);	//in2 LOW  Then Forward CLock Wise
}

void stop(vuint8_t* PORT_IN1,vuint8_t* PORT_IN2,uint8_t IN1_bitNumber , uint8_t IN2_bitNumber)
{
	*PORT_IN1 &= ~(1<<IN1_bitNumber);	//in1 LOW
	*PORT_IN2 &= ~(1<<IN2_bitNumber);	//in2 LOW
}

void move_backwards(vuint8_t* PORT_IN1,vuint8_t* PORT_IN2,uint8_t IN1_bitNumber , uint8_t IN2_bitNumber)
{
	*PORT_IN1 &= ~(1<<IN1_bitNumber);	//in1 LOW
	*PORT_IN2 |= (1<<IN2_bitNumber);	//in2 HIGH  Then BackWards anti CLock Wise
}

void set_speed(uint8_t percentage)
{
	uint8_t OCRO_value = ceil(((double)((double)percentage/(double)100))*(double)MaxNumber8bit);
	if(percentage >= 0 && percentage <= 100)
	Fast_PWM(OCRO_value);
}
