#pragma once
#include <stdio.h>
#include <string.h>

namespace Stacks
{
	struct StackElement
	{
		int value;
		StackElement *next;
	};

	struct Stack
	{
		StackElement *top;
		Stack()
		{
			top = nullptr;
		};

		~Stack()
		{
			while (top != nullptr)
			{
				StackElement *temp = top->next;
				delete top;
				top = temp;
			}
		};

		void push(int value);
		int pop(Stack *stack);
		void show();
		bool isEmpty(Stack* stack);
		void deleteTop(Stack* stack);
	};
}