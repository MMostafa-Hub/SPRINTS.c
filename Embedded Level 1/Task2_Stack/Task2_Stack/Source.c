#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#define maxSize 100


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



/*
Description : this Function cheks if the expression is blanaced or not 
input Args: expression -> string or char* or uin8_t*
output Args: none 
return : returns "Balanced" if the expression is balanced and returns "Not Balanced" if not
EX: "{(2+4)}" is Balanced 
	"{(2+4)*2)} is Not Balanced
*/
uint8_t* balancedParentheses(uint8_t* expression)
{
	for (int iterator = 0; iterator < strlen(expression); iterator++)
	{
		if (expression[iterator] == '{' || expression[iterator] == '(')
		{
			push(expression[iterator]);
		}
		else if (expression[iterator] == '}' || expression[iterator] == ')')
		{
			if ((expression[iterator] == '}' && top() != '{') || (expression[iterator] == ')' && top() != '(') || (sp == -1))
				return "Not Balanced";

			pull();
		}
	}
	if (sp != -1)
		return "Not Balanced";
	return "Balanced";
}


int main()
{
	uint8_t expression[maxSize];
	gets(expression);
	printf("%s", balancedParentheses(expression));
}