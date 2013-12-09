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


	struct List
	{
		ListElement *head;
		List()
		{
			head = nullptr;
		};
		~List()
		{
			while (head != nullptr)
			{
				ListElement *temp = head->next;
				delete head;
				head = temp;
			}
		};
		void addEl(int value);
		void deleteElement(ListElement* listElement);
		void deleteList();
		void show();
		List::ListElement *sortList(ListElement* listElement);
	};	
}