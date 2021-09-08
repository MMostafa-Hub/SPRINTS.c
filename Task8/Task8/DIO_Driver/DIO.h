/*
 * DIO.h
 *
 * Created: 4/9/2021 9:03:05 PM
 *  Author: OWNER
 */ 


#ifndef DIO_H_
#define DIO_H_


void DIO_init(int DRR_address ,int direction);
int DIo_read(int PIN_address);
void DIO_write(int PORT_address, int value);


#endif /* DIO_H_ */