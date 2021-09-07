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

#define Timer_control mem(0x53)
#define Timer_data mem(0x52)
#define Timer_flags mem(0x58)
#define Timer_overflow_flag (Timer_flags & 0x01)

#endif /* REGISTERS_H_ */