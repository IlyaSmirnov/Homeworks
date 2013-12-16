#pragma once
#include "binaryTree.h"

using namespace binaryTreeNS;

namespace sortedListNS
{
	struct ListElement
	{
		BinaryTree tree;
		int count;
		ListElement *next;
	};

	struct SortedList
	{
		ListElement *head;
	};
	
	SortedList createSortedList();
	void deleteSortedList(SortedList &list);

	void addValueToSortedList(SortedList &list, BinaryTree tree, int count);
	
	void makeTree(SortedList &list);
}