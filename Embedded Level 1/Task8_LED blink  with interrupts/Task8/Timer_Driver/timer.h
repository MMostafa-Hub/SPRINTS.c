/*
 * timer.h
 *
 * Created: 6/9/2021 10:40:00 PM
 *  Author: OWNER
 */ 


#ifndef TIMER_H_
#define TIMER_H_

void timer_init(int time);
void timer_delay(int time);

void timer_interr_init(void);
void timer_interr_delay(int time);

#endif /* TIMER_H_ */