#pragma once

namespace list
{
	struct ListElement
	{
		int value;
		ListElement *next;
	};

	struct List
	{
		ListElement *head; 
		ListElement *tail;
	};

	List createList();
	void deleteList(List &list);

	void addElement(List &list, int value);
	void deleteElement(List &list, ListElement *&listElement);
}