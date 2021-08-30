#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>


char stack[100];
int8_t sp = -1;
void push(uint8_t u8_data)
{
	sp++;
	stack[sp] = u8_data;
}
uint8_t pull()
{
	return stack[sp--];
}
uint8_t top()
{
	return stack[sp];
}

uint8_t* balancedParentheses(uint8_t* expression)
{
	for (int i = 0; i < strlen(expression); i++)
	{
		if (expression[i] == '{' || expression[i] == '(')
		{
			push(expression[i]);
		}
		else if (expression[i] == '}' || expression[i] == ')')
		{
			if ((expression[i] == '}' && top() == '(') || (expression[i] == ')' && top() == '{') || (sp == -1))
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
	uint8_t s[100];
	gets(s);
	printf("%s", balancedParentheses(s));
}