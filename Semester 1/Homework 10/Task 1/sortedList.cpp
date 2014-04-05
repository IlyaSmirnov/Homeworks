#include "sortedList.h"

using namespace sortedListNS;

void deleteElement(SortedList &list, ListElement *listElement)
{
	ListElement *temp;

	if (listElement == list.head)
	{
		temp = list.head;
		list.head = list.head->next;

		delete temp;
		temp = nullptr;

		return;
	}

	ListElement *counter = list.head;

	if (list.head != nullptr)
	{
		while ((counter != nullptr) && (counter->next != listElement))
			counter = counter->next;

		if (counter != nullptr)
		{
			temp = counter->next;
			counter->next = counter->next->next;

			delete temp;
			temp = nullptr;

			return;
		}
	}
}

BinaryTreeNode *pop(SortedList &list)
{
	BinaryTreeNode *temp = list.head->tree.root;

	deleteElement(list, list.head);

	return temp;
}

SortedList sortedListNS::createSortedList()
{
	SortedList list;
	list.head = nullptr;

	return list;
}

void sortedListNS::deleteSortedList(SortedList &list)
{
	while (list.head != nullptr)
	{
		ListElement *temp = list.head->next;

		deleteTree(list.head->tree);

		delete list.head;
		list.head = nullptr;

		list.head = temp;
	}

	delete list.head;
}

bool findSymbolInList(SortedList &list, BinaryTree tree)
{
	ListElement *current = list.head;

	while (current != nullptr)
	{
		if (tree.root->symbol == current->tree.root->symbol)
		{
			int tempCount = ++current->count;
			deleteTree(current->tree);
			deleteElement(list, current);
			
			addValueToSortedList(list, tree, tempCount);

			return true;
		}

		current = current->next;
	}

	return false;
}

void sortedListNS::addValueToSortedList(SortedList &list, BinaryTree tree, int count)
{
	if ((tree.root->symbol != '0') && findSymbolInList(list, tree))
		return;
	
	ListElement *temp = new ListElement;
	temp->count = count;
	temp->tree = tree;
	temp->next = nullptr;

	if (list.head == nullptr)
	{
		list.head = temp;
		return;
	}

	ListElement *current = list.head;

	current = list.head;
	ListElement *old = nullptr;
	temp->next = list.head;

	while (current != nullptr)
	{
		if (temp->count > current->count)
		{
			old = current;
			current = current->next;
		}
		else
		{
			if (old != nullptr)
			{
				old->next = temp;
				temp->next = current;
				return;
			}
			temp->next = current;
			list.head = temp;

			return;
		}
	}

	temp->next = nullptr;
	old->next = temp;
}

void sortedListNS::makeTree(SortedList &list)
{
	while (list.head->next != nullptr)
	{
		int count = list.head->count + list.head->next->count;

		BinaryTree tempTree = createTree(pop(list), pop(list), '0');

		addValueToSortedList(list, tempTree, count);
	}

	return;
}