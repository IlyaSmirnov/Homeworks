#include "reversePolishNotation.h"

#include "charStack.h"
using namespace CharStacks;

char *conversion(char *string)
{
	int i = 0;
	char *result = new char[255];

	CharStack *stack = new CharStack;

	for (unsigned int j = 0; string[j] != '\n'; ++j)
	{
		if ((string[j] >= '0') && (string[j] <= '9'))
		{
			result[i] = string[j];
			++i;
			continue;
		}
		if ((string[j] == '*') || (string[j] == '/'))
		{
			if (!stack->isEmpty(stack))
				while ((stack->top->value == '*') || (stack->top->value == '/'))
				{
					result[i] = stack->pop(stack);
					++i;
					if (stack->isEmpty(stack))
						break;
				}
				stack->push(string[j]);
				continue;
		}
		if ((string[j] == '+') || (string[j] == '-') || (string[j] == '('))
		{
			stack->push(string[j]);
			continue;
		}
		if (string[i] == ')')
		{
			while (stack->top->value != '(')
			{
				result[i] = stack->pop(stack);
				++i;
			}
			stack->deleteTop(stack);
			continue;
		}
	}

	while (stack->top != nullptr)
	{
		result[i] = stack->pop(stack);
		++i;
	}

	delete stack;
	return result;
}