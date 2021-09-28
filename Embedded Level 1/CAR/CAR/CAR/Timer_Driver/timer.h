/*
* timer.h
*
* Created: 8/9/2021 6:01:10 PM
*  Author: OWNER
*/


#ifndef TIMER_H_
#define TIMER_H_
#include "../macros.h"

void timer_pwm_init(void);
void Fast_PWM(uint8_t OCR0_);
void timer_delay(int time);
void timer_init(void);


#endif /* TIMER_H_ */