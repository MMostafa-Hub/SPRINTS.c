/*
 * stack.h
 *
 * Created: 21/9/2021 1:26:14 PM
 *  Author: OWNER
 */ 


#ifndef STACK_H_
#define STACK_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#define maxSize 1

//STACK
char stack[maxSize];
int8_t sp = -1;
void push(uint8_t u8_data)
{
	if (sp == maxSize - 1) // OVERFLOW GUARD
	return;
	stack[++sp] = u8_data;
}
uint8_t pull() // pop()
{
	if (sp == -1) // UNDERFOW GUARD
	return;
	return stack[sp--];
}
uint8_t top()
{
	if (sp == -1) // INVALID
	return;
	return stack[sp];
}

#endif /* STACK_H_ */