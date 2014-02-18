#include "charStack.h"
using namespace CharStacks;

#include "stack.h"
using namespace Stacks;

#include <stdlib.h>

#include "reversePolishNotation.h"

void popTwo(Stack *stack, int &firstEl, int &SecondEl)
{
	firstEl = stack->pop(stack);
	SecondEl = stack->pop(stack);
}

int main()
{
	printf_s("%s\n", "Welcome to the program of Reverse Polish notation calculator");

	char *string = new char[255];
	printf_s("%s\n", "Enter string");

	int i = 0;

	while (true)
	{
		string[i] = getchar();
		if (string[i] == '\n')
			break;
		i++;
	}

	char *convertedString = conversion(string);

	delete[] string;

	Stack *stack = new Stack;
	for (int j = 0; j < i; ++j)
	{
		if ((convertedString[j] >= '0') && (convertedString[j] <= '9'))
		{
			stack->push((char) convertedString[j] - 48);
			continue;
		}

		int temp1 = 0;
		int temp2 = 0;
		popTwo(stack, temp1, temp2);

		if (convertedString[j] == '+')
			stack->push(temp1 + temp2);

		if (convertedString[j] == '*')
			stack->push(temp1 * temp2);

		if (convertedString[j] == '-')
			stack->push(temp2 - temp1);

		if (convertedString[j] == '/')
			stack->push(temp2 / temp1);
	}

	stack->show();

	delete stack;

	delete [] convertedString;
	system("PAUSE");
	return 0;
}