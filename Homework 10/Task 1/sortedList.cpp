#include "sortedList.h"

using namespace sortedListNS;

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
		delete list.head;
		list.head = temp;
	}
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
	
	while ((current != nullptr) && tree.root->symbol != '0')
	{
		if (tree.root->symbol == current->tree.root->symbol)
		{
			++current->count;
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

BinaryTreeNode *pop(SortedList &list)
{
	BinaryTreeNode *temp = list.head->tree.root;
	
	list.head = list.head->next;

	return temp;
}

void sortedListNS::makeTree(SortedList &list)
{
	while (list.head->next != nullptr)
	{
		int count = list.head->count + list.head->next->count;

		BinaryTree tempTree = createTree();

		tempTree.root = new BinaryTreeNode;

		tempTree.root->leftChild = pop(list);
		tempTree.root->rightChild = pop(list);

		int const stringLength = 256;

		tempTree.root->symbol = '0';

		
		addValueToSortedList(list, tempTree, count);
	}

	return;
}