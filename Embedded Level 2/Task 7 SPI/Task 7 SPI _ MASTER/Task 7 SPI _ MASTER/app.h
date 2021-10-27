/*
 * app.h
 *
 * Created: 27/10/2021 5:50:08 PM
 *  Author: OWNER
 */ 


#ifndef APP_H_
#define APP_H_

void app_init();


#include "SPI/spi.h"
#include "USART/usart.h"
#include <string.h>
#include <util/delay.h> /* To use the delay functions */
#define BAUD_RATE 9600

#endif /* APP_H_ */