#pragma once
#include "binaryTree.h"
#include <iostream>

using namespace binaryTreeNS;

namespace listNS
{
	struct ListElement
	{
		BinaryTree tree;
		ListElement *next;
	};

	struct List
	{
		ListElement *head;
	};

	List createList();
	void deleteList(List &list);

	//void addElementToList(List &list, String string);
	//void deleteElementInList(List &list, ListElement *&listElement);
	//bool findInList(List list, String string);

	void showList(List list);
	bool isEmptyList(List list);
}