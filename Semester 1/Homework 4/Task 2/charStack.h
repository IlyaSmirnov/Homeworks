#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

namespace CharStacks
{
	struct CharStackElement
	{
		char value;
		CharStackElement *next;
	};

	struct CharStack
	{
		CharStackElement *top;
		CharStack()
		{
			top = nullptr;
		};

		~CharStack()
		{
			while (top != nullptr)
			{
				CharStackElement *temp = top->next;
				delete top;
				top = temp;
			}
		};

		void push(char value);
		int pop(CharStack* stack);
		void show();
		bool isEmpty(CharStack* stack);
		void deleteTop(CharStack* stack);
	};
}