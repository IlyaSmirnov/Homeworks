#include "binaryTree.h"
#include <iostream>

using namespace binaryTreeNS;
using namespace std;

BinaryTree binaryTreeNS::createTree(BinaryTreeNode *leftChild, BinaryTreeNode *rightChild, char symbol)
{
	BinaryTree tree;

	tree.root = nullptr;
	tree.root = new BinaryTreeNode;

	tree.root->leftChild = leftChild;
	tree.root->rightChild = rightChild;
	tree.root->symbol = symbol;
	
	return tree;
}

BinaryTreeNode *binaryTreeNS::createTreeNode(char symbol)
{
	BinaryTreeNode *node = new BinaryTreeNode;

	node->leftChild = node->rightChild = nullptr;
	node->symbol = symbol;

	return node;
}

void deleteTreeNode(BinaryTree &tree, BinaryTreeNode *&child)
{
	if (child != nullptr)
	{
		if (child->leftChild != nullptr)
			deleteTreeNode(tree, child->leftChild);

		if (child->rightChild != nullptr)
			deleteTreeNode(tree, child->rightChild);

		delete child;
		child = nullptr;
	}

	return;
}

void binaryTreeNS::deleteTree(BinaryTree &tree)
{
	return deleteTreeNode(tree, tree.root);
}

void print(BinaryTreeNode *child)
{
	if (child == nullptr)
		cout << "null";
	else
	{
		cout << "(" << "" << child->symbol << " ";
		print(child->leftChild);

		cout << " ";

		print(child->rightChild);
		cout << ")";
	}

	return;
}

void read(char *string, int &index, BinaryTreeNode *current)
{
	if (strlen(string) <= index + 1)
		return;

	while (string[index + 1] != ')')
	{
		int keyIndex = 0;

		if ((string[index - 1] == '(') && (string[index + 1] == ' '))
		{
			keyIndex = index;
			index += 2;
		}

		if (string[index] == '(')
		{
			current->leftChild = createTreeNode('0');
			read(string, ++index, current->leftChild);
			index += 2;

			current->rightChild = createTreeNode('0');
			read(string, ++index, current->rightChild);
			index += 2;

			return;
		}

		if (keyIndex != 0)
			current->symbol = string[keyIndex];

		++index;
	}

	++index;

	return;
}

BinaryTree binaryTreeNS::readTree(char *string)
{
	BinaryTree tree = createTree(nullptr, nullptr, '0');

	int index = 1;

	read(string, index, tree.root);
	delete[] string;

	return tree;
}