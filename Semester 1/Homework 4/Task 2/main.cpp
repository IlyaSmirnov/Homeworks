#include "CharStack.h"
using namespace CharStacks;

bool isNumber(char stringElement)
{
	return ((stringElement >= '0') && (stringElement <= '9'));
}

bool isMultOrDiv(char stringElement)
{
	return ((stringElement == '*') || (stringElement == '/'));
}

bool isPlusOrMinusOrOpeningBracket(char stringElement)
{
	return ((stringElement == '+') || (stringElement == '-') || (stringElement == '('));
}

bool isClosingBracket(char stringElement)
{
	return (stringElement == ')');
}

int main()
{
	printf_s("%s\n", "Welcome to the program of realization of Shunting-yard algorithm");
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
		
	printf_s("%s\n", "Your expression in Reverse Polish notation:");
	CharStack *stack = new CharStack;

	for (unsigned int i = 0; i < strlen(string); ++i)
	{
		if (isNumber(string[i]))
		{
			printf("%c", string[i]);
			continue;
		}

		if (isMultOrDiv(string[i]))
		{
			if (!stack->isEmpty(stack))
				while ((stack->top->value == '*') || (stack->top->value == '/'))
				{
					printf("%c", stack->pop(stack));
					if (stack->isEmpty(stack))
						break;
				}
			stack->push(string[i]);
			continue;
		}

		if (isPlusOrMinusOrOpeningBracket(string[i]))
		{
			stack->push(string[i]);
			continue;
		}

		if (isClosingBracket(string[i]))
		{
			while (stack->top->value != '(')
			{
				printf("%c", stack->pop(stack));
			}
			stack->deleteTop(stack);
			continue;
		}
	}

	stack->show();
	printf("\n");
	system("PAUSE");

	delete[] string;
	delete stack;

	return 0;
}
