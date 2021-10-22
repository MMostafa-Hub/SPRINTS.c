/*
 * dio.h
 *
 * Created: 8/9/2021 6:00:59 PM
 *  Author: OWNER
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../macros.h"

void DIO_init(vuint8_t* PORT_, vuint8_t* DDR_, uint8_t dircetion, uint8_t bitNumber);
uint8_t DIO_read (vuint8_t* PIN_, uint8_t bitNumber);
void DIO_write(vuint8_t* PORT_, uint8_t bitNumber, uint8_t value);

#endif /* DIO_H_ */