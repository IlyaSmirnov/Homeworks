#include "list.h"

using namespace list;
using namespace std;

List list::createList()
{
	List list;
	list.head = nullptr;
	list.size = 0;

	return list;
}

void list::deleteList(List &list)
{
	while (list.head != nullptr)
	{
		ListElement *temp = list.head->next;
		deleteString(list.head->string);
		delete list.head;
		list.head = temp;
	}

	delete list.head;
}

void list::addElementToList(List &list, String string)
{
	ListElement *temp = new ListElement;
	temp->string = string;
	temp->next = nullptr;
	temp->number = 1;

	if (list.head == nullptr)
	{
		list.head = temp;
		list.size++;

		return;
	}
	else
	{
		ListElement *i = list.head;
		while (i != nullptr)
		{
			if (isEqualStrings(i->string, string))
			{
				++i->number;

				return;
			}

			i = i->next;
		}
		
		temp->next = list.head;
		list.head = temp;
		list.size++;

		return;
	}
}

void list::deleteElementInList(List &list, ListElement *&listElement)
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

void list::showList(List &list)
{
	if (list.head != nullptr)
	{
		ListElement *temp = list.head;

		while (temp != nullptr)
		{
			cout << temp->string.string << ' ' << temp->number << endl;
			temp = temp->next;
		}
	}

	return;
}

bool list::isEmptyList(List list)
{
	return (list.head == nullptr);
}