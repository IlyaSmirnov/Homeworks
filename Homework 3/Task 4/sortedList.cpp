#include "sortedLists.h"
using namespace list;

void SortedList::addEl(int value)
{
	ListElement *temp = new ListElement;

	temp->value = value;
	temp->next = head;
	head = temp;

	return;
}

void SortedList::deleteElement(ListElement* listElement)
{
	ListElement *counter = head;
	ListElement *temp;

	if (listElement == head)
	{
		temp = head;
		head = head->next;
		delete temp;
		return;
	}

	if ((head != nullptr) && (head != listElement))
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
		if (head != listElement)
		{
			temp = listElement;
			head = listElement->next;
			delete temp;
			return;
		}
}

void SortedList::deleteList()
{
	while (head != nullptr)
	{
		ListElement *temp = head->next;
		delete head;
		head = temp;
	}

	return;
}

void SortedList::show()
{
	ListElement *temp = head;

	while (temp != nullptr)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
	}

	return;
}

void SortedList::addValue(int value)
{
	ListElement *temp = new ListElement;
	temp->value = value;
	temp->next = nullptr;

	if (head == nullptr)
	{
		head = temp;
		return;
	}

	ListElement *current;
	current = head;
	ListElement *old = nullptr;
	
	temp->next = head;
	while (current != nullptr)
	{
		if (current->value < temp->value)
		{
			old = current;
			current = current->next;
		}
		else
		{
			if (old != nullptr)
			{
				old->next = temp;
				temp->next = current;
				return;
			}
			temp->next = current;
			head = temp;
			return;
		}
	}
	temp->next = nullptr;
	old->next = temp;
}

void SortedList::removeValue(int value)
{
	ListElement *temp = head;

	while (temp != nullptr)
	{
		if (temp->value == value)
		{
			deleteElement(temp);
			return;
		}

		temp = temp->next;
	}

	return;
}