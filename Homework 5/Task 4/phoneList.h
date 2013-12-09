#pragma once
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <string.h>

namespace Phone
{
struct PhoneListElement
	{
		char * name;
		int number;
		PhoneListElement *next;
	};

	struct PhoneList
	{
		PhoneListElement *head;
		PhoneList()
		{
			head = nullptr;
		};

		~PhoneList()
		{
			while (head != nullptr)
			{
				PhoneListElement *temp = head->next;
				delete [] head->name;
				delete head;
				head = temp;
			}
		};

		void addEl(char* name, int number);
		int findByName(char* name);
		char* findByNumber(int number);
		void saveInFile(PhoneList* list);
	};	
}