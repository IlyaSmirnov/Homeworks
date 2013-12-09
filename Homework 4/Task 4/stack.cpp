#include "stack.h"
using namespace Stacks;

void Stack::deleteTop(Stack* stack)
{
	if (!isEmpty(stack))
	{
		StackElement* temp = stack->top;
		stack->top = stack->top->next;
		delete(temp);
	}
}

bool Stack::isEmpty(Stack* stack)
{
	return(stack->top == nullptr);
}

void Stack::push(int value)
{
	StackElement *temp = new StackElement;
	temp->value = value;
	temp->next = top;
	top = temp;
}

int Stack::pop(Stack* stack)
{
	int result = stack->top->value;
	if (!isEmpty(stack))
	{
		StackElement* temp = stack->top;
		stack->top = stack->top->next;
		delete(temp);
	}
	return result;
}

void Stack::show()
{
	StackElement *temp = top;
	while (temp != nullptr)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
	}


}