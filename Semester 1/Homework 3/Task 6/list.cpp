#include "list.h"
using namespace lists;

void List::addEl(int value)
{
	ListElement *temp = new ListElement;
	temp->value = value;
	if (head != nullptr) {
	temp->next = head;
	head = temp;
	}
	else
	{
		temp->next = nullptr;
		head = temp;
	}
}

void List::deleteElement(ListElement* listElement)
{
	ListElement *counter = head;
	ListElement *temp;

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
	{
		if (head != listElement)
		{
			temp = listElement;
			head = listElement->next;
			delete temp;
			return;
		}
	}
}

void List::deleteList()
{
	while (head != nullptr)
	{
		ListElement *temp = head->next;
		delete head;
		head = temp;
	}
}

void List::show()
{
	ListElement *temp = head;
	while (temp != nullptr)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
	}
}
ListElement *List::sortList(ListElement* listElement)
{
	ListElement *head = 0; 
	while (listElement != 0)
	{
		ListElement * current = listElement;
		listElement = listElement->next;
		if (!head || current->value < head->value)
		{
			current->next = head;
			head = current;
		}
		else
		{
			ListElement * temp = head;
			while (temp)
			{
				if (!temp->next || current->value < temp->next->value)
				{
					current->next = temp->next;
					temp->next = current;
					break;
				}
				temp = temp->next;
			}
		}
	}
	return head;
}