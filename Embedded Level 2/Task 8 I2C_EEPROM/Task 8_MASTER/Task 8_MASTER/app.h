/*
 * app.h
 *
 * Created: 25/10/2021 8:38:35 PM
 *  Author: OWNER
 */ 


#ifndef APP_H_
#define APP_H_

#include "EXTERNAL_EEPROM/external_eeprom.h"
#include "DIO/dio.h"
#include "util/delay.h"
#include "TWI/twi.h"
#include "USART/usart.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

void app_init(void);
uint16 power(uint8 num, uint8 p);
uint16 string_to_binary_to_decimal(uint8 s_eeprom_mem_address[], uint8 size);


#endif /* APP_H_ */