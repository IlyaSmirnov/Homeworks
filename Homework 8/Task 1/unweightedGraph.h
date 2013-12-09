#pragma once
#include <stdlib.h>
#include <iostream>
#include <fstream>

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
		char name;
		bool visit;
	};

	List create();
	void deleteList(List &list);

	void addEl(List &list, int value);
	void deleteElement(List &list, ListElement *&listElement);

	void DFS(List graph[], int i, int number);
	
	void show(List &list, int i);
}