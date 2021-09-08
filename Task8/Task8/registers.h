/*
 * registers.h
 *
 * Created: 4/9/2021 9:03:40 PM
 *  Author: OWNER
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

#define mem(x) (*(volatile unsigned char*)(x))

#define PORTA_DIR mem(0x3A)
#define PORTA_Data mem(0x3B)

#define PORTC_DIR mem(0x34)
#define PINC_Data mem(0x33)


#define PORTA_DIR_addr (0x3A)
#define PORTA_Data_addr (0x3B)

#define PORTC_DIR_addr (0x34)
#define PINC_Data_addr (0x33)

#define Timer0_control mem(0x53)
#define Timer0_data mem(0x52)
#define Timer0_flags mem(0x58)
#define Timer0_overflow_flag (Timer0_flags & 0x01)

#define Timer1_control_regA mem(0x4f)
#define Timer1_control_regB mem(0x4e)
#define Timer1_interr_mask mem(0x59)
#endif /* REGISTERS_H_ */