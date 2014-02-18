#include "charStack.h"
using namespace CharStacks;

void CharStack::deleteTop(CharStack* stack)
{
	if (!isEmpty(stack))
	{
		CharStackElement* temp = stack->top;
		stack->top = stack->top->next;
		delete(temp);
	}
}

bool CharStack::isEmpty(CharStack* stack)
{
	return(stack->top == nullptr);
}

void CharStack::push(char value)
{
	CharStackElement *temp = new CharStackElement;
	temp->value = value;
	temp->next = top;
	top = temp;
}

int CharStack::pop(CharStack* stack)
{
	int result = stack->top->value;
	if (!isEmpty(stack))
	{
		CharStackElement* temp = stack->top;
		stack->top = stack->top->next;
		delete temp;
	}
	return result;
}

void CharStack::show()
{
	CharStackElement *temp = top;
	while (temp != nullptr)
	{
		printf("%c", temp->value);
		temp = temp->next;
	}
}