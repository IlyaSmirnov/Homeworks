#pragma once
#include <stdio.h>
#include <string.h>

namespace list
{
	struct ListElement
	{
		int value;
		ListElement *next;
	};

	struct SortedList
	{
		ListElement *head;
		
		SortedList()
		{
			head = nullptr;
		}
		
		~SortedList()
		{
			while (head != nullptr)
			{
				ListElement *temp = head->next;
				delete head;
				head = temp;
			}
		}

		void addEl(int value);
		void deleteElement(ListElement* listElement);
		void deleteList();
		void show();
		void addValue(int value);
		void removeValue(int value);
	};
}