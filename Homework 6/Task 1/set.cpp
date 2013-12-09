#include "set.h"

using namespace TreeADT;

BinaryTree TreeADT::create()
{
	BinaryTree tree;
	tree.root = nullptr;
	return tree;
}

BinaryTreeNode* createTemp(int value)
{
	BinaryTreeNode * temp = new BinaryTreeNode;

	temp->value = value;
	temp->leftChild = nullptr;
	temp->rightChild = nullptr;

	return temp;
}

void deleteTreeNodeWithNodeAsArgument(BinaryTree &tree, BinaryTreeNode *&child)
{
	if (child != nullptr)
	{
		if (child->leftChild != nullptr)
			deleteTreeNodeWithNodeAsArgument(tree, child->leftChild);

		if (child->rightChild != nullptr)
			deleteTreeNodeWithNodeAsArgument(tree, child->rightChild);

		delete child;
		child = nullptr;
	}

	return;
}

void TreeADT::deleteTree(BinaryTree &tree)
{
	if (tree.root != nullptr)
		deleteTreeNodeWithNodeAsArgument(tree, tree.root);

	return;
}

void addValueWithNodeAsArgument(BinaryTree &tree, BinaryTreeNode *&current, int value)
{
	if (current->value == value)
		return;

	if (current->value < value)
	{
		if (current->rightChild == nullptr)
		{
			current->rightChild = createTemp(value);

			return;
		}

		addValueWithNodeAsArgument(tree, current->rightChild, value);

		return;
	}

	if (current->value > value)
	{
		if (current->leftChild == nullptr)
		{
			current->leftChild = createTemp(value);

			return;
		}

		addValueWithNodeAsArgument(tree, current->leftChild, value);

		return;
	}
}

void TreeADT::addValue(BinaryTree &tree, int value)
{
	if (tree.root == nullptr)
	{
		tree.root = createTemp(value);

		return;
	}

	addValueWithNodeAsArgument(tree, tree.root, value);

	return;
}

int findTheSmallestValueAndDestroyIt(BinaryTree &tree, BinaryTreeNode *&root)
{
	if (root->leftChild != nullptr)
		return findTheSmallestValueAndDestroyIt(tree, root->leftChild);
	else
	{
		int temp = root->value;

		delete root;
		root = nullptr;

		return temp;
	}
}

void removeValueWithNodeAsArgument(BinaryTree &tree, BinaryTreeNode *&child, int value)
{
	if (child->value == value)
	{
		if ((child->leftChild == nullptr) && (child->rightChild == nullptr))
		{
			delete child;
			child = nullptr;

			return;
		}

		if ((child->leftChild != nullptr) && (child->rightChild == nullptr))
		{
			BinaryTreeNode *temp = child;

			child = child->leftChild;
			delete temp;

			return;
		}

		if ((child->leftChild == nullptr) && (child->rightChild != nullptr))
		{
			BinaryTreeNode *temp = child;

			child =  child->rightChild;
			delete temp;
			
			return;
		}

		if ((child->leftChild != nullptr) && (child->rightChild != nullptr))
		{
			child->value = findTheSmallestValueAndDestroyIt(tree, child->rightChild);

			return;
		}
	}

	if ((child->value > value) && (child->leftChild != nullptr))
		removeValueWithNodeAsArgument(tree, child->leftChild, value);

	if ((child->value < value) && (child->rightChild != nullptr))
		removeValueWithNodeAsArgument(tree, child->rightChild, value);

	return;
}

void TreeADT::removeValue(BinaryTree &tree, int value)
{
	if (tree.root != nullptr)
		removeValueWithNodeAsArgument(tree, tree.root, value);

	return;
}

bool existWithNodeAsArgument(BinaryTree &tree, BinaryTreeNode *child, int value)
{
	if (child->value == value)
		return	true;

	if (value < child->value)
		if (child->leftChild == nullptr)
			return false;
		else
			return existWithNodeAsArgument(tree, child->leftChild, value);

	if (value > child->value)
		if (child->rightChild == nullptr)
			return false;
		else
			return existWithNodeAsArgument(tree, child->rightChild, value);
}

bool TreeADT::exist(BinaryTree &tree, int value)
{
	return existWithNodeAsArgument(tree, tree.root, value);
}

void printAscenndingWithNodeAsArgument(BinaryTree &tree, BinaryTreeNode *child)
{
	if (child != nullptr)
	{
		if (child->leftChild != nullptr)
			printAscenndingWithNodeAsArgument(tree, child->leftChild);

		printf("%d%c", child->value, ' ');

		if (child->rightChild != nullptr)
			printAscenndingWithNodeAsArgument(tree, child->rightChild);
	}

	return;
}

void TreeADT::printAscennding(BinaryTree &tree)
{
	printAscenndingWithNodeAsArgument(tree, tree.root);

	return;
}

void printDescendingWithNodeAsArgument(BinaryTree &tree, BinaryTreeNode *child)
{
	if (child != nullptr)
	{
		if (child->rightChild != nullptr)
			printDescendingWithNodeAsArgument(tree, child->rightChild);

		printf("%d%c", child->value, ' ');

		if (child->leftChild != nullptr)
			printDescendingWithNodeAsArgument(tree, child->leftChild);
	}

	return;
}

void TreeADT::printDescending(BinaryTree &tree)
{
	printDescendingWithNodeAsArgument(tree, tree.root);

	return;
}

void SomeOrderWithNodeAsArgumant(BinaryTree &tree, BinaryTreeNode *child)
{
	printf("%c%d%c", '(', child->value, ' ');

	if (child->leftChild == nullptr)
		printf("%s", "null");
	else
		SomeOrderWithNodeAsArgumant(tree, child->leftChild);

	printf("%c", ' ');

	if (child->rightChild == nullptr)
		printf("%s", "null");
	else
		SomeOrderWithNodeAsArgumant(tree, child->rightChild);

	printf("%s", ")");

	return;
}

void TreeADT::printSomeOrder(BinaryTree &tree)
{
	SomeOrderWithNodeAsArgumant(tree, tree.root);

	return;
}