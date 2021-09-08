/*
 * led.h
 *
 * Created: 4/9/2021 9:35:38 PM
 *  Author: OWNER
 */ 


#ifndef LED_H_
#define LED_H_


void led_init(void);
void led_ON(void);
void led_OFF(void);
void led_ON_delay(int time);
void led_OFF_delay(int time);
void led_blink(int time);
void led_blink_interr(int time);


#endif /* LED_H_ */