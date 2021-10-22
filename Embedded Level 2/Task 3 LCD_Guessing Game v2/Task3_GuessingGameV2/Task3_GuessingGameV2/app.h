/*
 * app.h
 *
 * Created: 21/9/2021 6:39:32 PM
 *  Author: OWNER
 */ 


#ifndef APP_H_
#define APP_H_


#include "macros.h"

void app_init(void);
void render_main_screen(void);
void render_win_screen(char* number);
void render_loss_screen(char* number);
void render_range_invalid_screen(void);
void render_invalid_input_screen(void);
uint8_t rand_int(uint8_t seed, uint8_t range);



#endif /* APP_H_ */