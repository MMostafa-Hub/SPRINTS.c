/*
 * led.h
 *
 * Created: 10/9/2021 1:32:08 PM
 *  Author: OWNER
 */ 


#ifndef LED_H_
#define LED_H_

#include "../DIO/dio.h"
#include "../Led/led.h"
#include "../macros.h"

void led_init(vuint8_t* PORT_, vuint8_t* DDR_, int8_t bitNumber);
void led_write(vuint8_t* PORT_, int8_t bitNumber, int8_t value);


#endif /* LED_H_ */