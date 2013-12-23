#include "sortedList.h"

using namespace sortedListNS;

void deleteElement(SortedList &list, ListElement* listElement)
{
	ListElement *counter = list.head;
	ListElement *temp;

	if (listElement == list.head)
	{
		temp = list.head;
		list.head = list.head->next;

		delete temp;
		temp = nullptr;

		return;
	}

	if ((list.head != nullptr) && (list.head != listElement))
	{
		while ((counter != nullptr) && (counter->next != listElement))
			counter = counter->next;

		if (counter)
		{
			temp = counter->next;
			counter->next = counter->next->next;

			delete temp;
			temp = nullptr;

			return;
		}
	}
	else
		if (list.head != listElement)
		{
			temp = listElement;
			list.head = listElement->next;

			delete temp;
			temp = nullptr;

			return;
		}
}

void removeValue(SortedList &list, BinaryTree tree)
{
	ListElement *temp = list.head;

	while (temp != nullptr)
	{
		if (temp->tree.root->symbol == tree.root->symbol)
		{
			deleteElement(list, temp);

			return;
		}

		temp = temp->next;
	}

	return;
}

BinaryTreeNode *pop(SortedList &list)
{
	BinaryTreeNode *temp = list.head->tree.root;

	list.head = list.head->next;

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

void sortedListNS::addValueToSortedList(SortedList &list, BinaryTree tree, int count)
{
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
	
	while ((current != nullptr) && (tree.root->symbol != '0'))
	{
		if (tree.root->symbol == current->tree.root->symbol)
		{
			BinaryTree tempTree = createTempTree(nullptr, nullptr, current->tree.root->symbol);
			int tempCount = ++current->count;
			removeValue(list, current->tree);
			addValueToSortedList(list, tempTree, tempCount);

			return;
		}

		current = current->next;
	}

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

		BinaryTree tempTree = createTempTree(pop(list), pop(list), '0');

		addValueToSortedList(list, tempTree, count);
	}

	return;
}