/*
 * app.h
 *
 * Created: 11/9/2021 11:55:40 AM
 *  Author: OWNER
 */ 


#ifndef APP_H_
#define APP_H_
#include "macros.h"

void app_init();
void car_forward(void);
void car_bacwards(void);
void car_stop(void);
void car_rotate_left(void);
void car_rotate_right(void);
void setState(uint8_t state);
uint8_t is_button_pressed(uint8_t button_bit_number);


#endif /* APP_H_ */