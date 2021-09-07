/*
 * registers.h
 *
 * Created: 4/9/2021 9:03:40 PM
 *  Author: OWNER
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

#define mem(x) (*(volatile unsigned char*)(x))

#define PORTA_DIR (*(volatile unsigned char*)(0x3A))
#define PORTA_Data (*(volatile unsigned char*)(0x3B))	

#define PORTC_DIR (*(volatile unsigned char*)(0x34))
#define PINC_Data (*(volatile unsigned char*)(0x33))

#define PORTA_DIR_addr (0x3A)
#define PORTA_Data_addr (0x3B)

#define PORTC_DIR_addr (0x34)
#define PINC_Data_addr (0x33)



#endif /* REGISTERS_H_ */