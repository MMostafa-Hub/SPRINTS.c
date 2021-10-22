/*
 * app.h
 *
 * Created: 20/9/2021 2:00:39 PM
 *  Author: OWNER
 */ 


#ifndef APP_H_
#define APP_H_

void app_init(void);
void render_main_screen(void);
void render_win_screen(char* rand_number);
void render_loss_screen(char* rand_number);
void render_range_invalid_screen();
uint8_t rand_int(uint8_t seed,uint8_t range);




#endif /* APP_H_ */