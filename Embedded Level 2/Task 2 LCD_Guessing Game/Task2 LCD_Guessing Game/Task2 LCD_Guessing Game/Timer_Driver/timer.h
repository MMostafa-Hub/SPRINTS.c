/*
 * timer.h
 *
 * Created: 16/9/2021 2:41:40 PM
 *  Author: OWNER
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "../macros.h"

void timer_delay(uint16_t time);
void __vector_9 (void) __attribute__ ((signal,used)) ;
void __vector_9 (void);
void timer_interr_delay(int time) ;


#endif /* TIMER_H_ */