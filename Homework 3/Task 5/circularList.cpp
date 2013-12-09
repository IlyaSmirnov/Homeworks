#include "CircularList.h"
using namespace lists;


void CircularList::addEl(int value)
{
	ListElement *temp = new ListElement;
	temp->next = head;
	temp->value = value;
	if (head != nullptr)
	{
		tail->next = temp;
		tail = temp;
	}
	else
		head = tail = temp;
}

void CircularList::deleteAndGoOn(ListElement* counter)
{
	ListElement *temp = counter->next;
	counter->next = counter->next->next;
	delete temp;
}

void CircularList::deleteElement(ListElement* listElement)
{
	ListElement *counter = head;
	
	while ((counter->next != head) && (counter->next != listElement))
		counter = counter->next;

	if ((counter->next != head) && (counter->next != tail))
	{
		deleteAndGoOn(counter);
		return;
	}

	if (counter->next == head)
	{
		head = counter->next->next;
		deleteAndGoOn(counter);
		return;
	}

	if (counter->next == tail)
	{
		head = counter->next->next->next;
		tail = counter->next->next;
		deleteAndGoOn(counter);
		return;
	}
}

void CircularList::deleteList()
{
	while (head != tail)
	{
		ListElement *temp = head->next;
		delete head;
		head = temp;
	}
}