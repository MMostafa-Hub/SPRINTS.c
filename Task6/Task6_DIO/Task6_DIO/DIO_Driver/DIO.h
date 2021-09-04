/*
 * DIO.h
 *
 * Created: 4/9/2021 9:03:05 PM
 *  Author: OWNER
 */ 


#ifndef DIO_H_
#define DIO_H_

void DIO_init_PortC();
void DIO_init_PortA();
int DIO_read_portC();
void DIO_write_PortA(int value);



#endif /* DIO_H_ */