#include "Stack.h"
#include <stdlib.h>
using namespace Stacks;

void popTwo(Stack *stack, int &firstEl, int &SecondEl)
{
	firstEl = stack->pop(stack);
	SecondEl = stack->pop(stack);
}

int main()
{
	printf("%s\n", "Welcome to the program which calculate the expression in Reverse Polish notion");
	printf("%s\n", "Enter your expression");

	char* string = new char[255];
	int i = 0;
	Stack *stack = new Stack;

	while (true)
	{
		string[i] = getchar();
		if (string[i] == '\n')
			break;
				
		if ((string[i] >= '0') && (string[i] <= '9'))
		{
			stack->push(atoi(&string[i]));
			continue;
		}

		int temp1 = 0;
		int temp2 = 0;
		popTwo(stack, temp1, temp2);

		if (string[i] == '+')
			stack->push(temp1 + temp2);
		
		if (string[i] == '*')
			stack->push(temp1 * temp2);
				
		if (string[i] == '-')
			stack->push(temp2 - temp1);
		
		if (string[i] == '/')
			stack->push(temp2 / temp1);
		
		i++;
	}

	printf("%s\n", "Result:");
	stack->show();

	delete[] string;
	delete stack;

	system("PAUSE");
	return 0;
}