#pragma once
#include "string.h"
#include <iostream>

using namespace stringNS;

namespace list
{
	struct ListElement
	{
		String string;
		int number;
		ListElement *next;
	};

	struct List
	{
		int size;
		ListElement *head;
	};

	List createList();
	void deleteList(List &list);

	void addElementToList(List &list, String string);
	void deleteElementInList(List &list, ListElement *&listElement);
	bool findInList(List list, String string);

	void showList(List list);
	bool isEmptyList(List list);
}