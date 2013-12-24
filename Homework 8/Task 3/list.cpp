#include "list.h"

using namespace list;

List list::createList()
{
	List list;
	list.head = list.tail = nullptr;

	return list;
}

void list::deleteList(List &list)
{
	while (list.head != nullptr)
	{
		ListElement *temp = list.head->next;
		delete list.head;
		list.head = temp;
	}
}

void list::addElement(List &list, int value)
{
	ListElement *temp = new ListElement;
	temp->value = value;
	temp->next = nullptr;

	if (list.head != nullptr)
	{
		list.tail->next = temp;
		list.tail = temp;
	}
	else	
		list.head = list.tail = temp;
}

void list::deleteElement(List &list, ListElement *&listElement)
{
	ListElement *counter = list.head;
	ListElement *temp;

	if ((list.head != nullptr) && (list.head != listElement))
	{
		while ((counter != nullptr) && (counter->next != listElement))
			counter = counter->next;
		if (counter)
		{
			temp = counter->next;
			counter->next = counter->next->next;
			delete temp;
			return;
		}
	}
	else
	{
		if (list.head != listElement)
		{
			temp = listElement;
			list.head = listElement->next;
			delete temp;
			return;
		}
	}
}