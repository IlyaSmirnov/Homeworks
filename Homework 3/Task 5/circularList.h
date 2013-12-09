#pragma once
#include <stdio.h>
#include <string.h>

namespace lists
{
	struct ListElement
	{
		int value;
		ListElement *next;
	};
	
	struct CircularList
	{
		ListElement *head, *tail;
		CircularList()
		{
			head = tail = nullptr;
		}
		~CircularList()
		{
			while (head != tail)
			{
				ListElement *temp = head->next;
				delete head;
				head = temp;
			}
		}
		void addEl(int x);
		void deleteElement(ListElement* listElement);
		void deleteList();
		void removeValue(int value);
		void deleteAndGoOn(ListElement* counter);
	};
}