#ifndef MOTOR_H_
#define MOTOR_H_
#include "../macros.h"
#include "../DIO_Driver/dio.h"
#include "../Timer_Driver/timer.h"
#include <math.h>

void motor_init(vuint8_t* PORT_IN1,vuint8_t* PORT_IN2,vuint8_t* IN1_DDR, vuint8_t* IN2_DDR,uint8_t IN1_bitNumber , uint8_t IN2_bitNumber);
void move_forward(vuint8_t* PORT_IN1,vuint8_t* PORT_IN2,uint8_t IN1_bitNumber , uint8_t IN2_bitNumber);
void stop(vuint8_t* PORT_IN1,vuint8_t* PORT_IN2,uint8_t IN1_bitNumber , uint8_t IN2_bitNumber);
void move_backwards(vuint8_t* PORT_IN1,vuint8_t* PORT_IN2,uint8_t IN1_bitNumber , uint8_t IN2_bitNumber);
void set_speed(uint8_t percentage);


#endif /* MOTOR_H_ */