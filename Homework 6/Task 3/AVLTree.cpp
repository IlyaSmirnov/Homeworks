#include "AVLTree.h"

using namespace TreeADT;

int height(BinaryTreeNode *node)
{
	return node ? node->height : 0;
}

int balanceFactor(BinaryTreeNode *node)
{
	return height(node->rightChild) - height(node->leftChild);
}

void updateHeight(BinaryTreeNode *node)
{
	int heightLeft = height(node->leftChild);
	int heightRight = height(node->rightChild);
	node->height = ((heightLeft > heightRight) ? heightLeft : heightRight) + 1;
}

BinaryTreeNode* rotateRight(BinaryTreeNode* root)
{
	BinaryTreeNode* pivot = root->leftChild;
	root->leftChild = pivot->rightChild;
	pivot->rightChild = root;
	updateHeight(root);
	updateHeight(pivot);
	return pivot;
}

BinaryTreeNode* rotateLeft(BinaryTreeNode* root)
{
	BinaryTreeNode* pivot = root->rightChild;
	root->rightChild = pivot->leftChild;
	pivot->leftChild = root;
	updateHeight(root);
	updateHeight(pivot);
	return pivot;
}

BinaryTreeNode* balance(BinaryTreeNode* p)
{
	updateHeight(p);

	if (balanceFactor(p) == 2)
	{
		if (balanceFactor(p->rightChild) < 0)
			p->rightChild = rotateRight(p->rightChild);

		return rotateLeft(p);
	}

	if (balanceFactor(p) == -2)
	{
		if (balanceFactor(p->leftChild) > 0)
			p->leftChild = rotateLeft(p->leftChild);

		return rotateRight(p);
	}

	return p;
}

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
	temp->height = 1;

	return temp;
}

void deleteNode(BinaryTree &tree, BinaryTreeNode *&child)
{
	if (child != nullptr)
	{
		if (child->leftChild != nullptr)
			deleteNode(tree, child->leftChild);

		if (child->rightChild != nullptr)
			deleteNode(tree, child->rightChild);

		delete child;
		child = nullptr;
	}

	return;
}

void TreeADT::deleteTree(BinaryTree &tree)
{
	if (tree.root != nullptr)
		deleteNode(tree, tree.root);

	return;
}

void addNodeValue(BinaryTree &tree, BinaryTreeNode *&current, int value)
{
	if (current->value == value)
		return;

	if (current->value < value)
	{
		if (current->rightChild == nullptr)
		{
			current->rightChild = createTemp(value);
			updateHeight(current);
			return;
		}
		addNodeValue(tree, current->rightChild, value);
		updateHeight(current);
		current = balance(current);
		return;
	}

	if (current->value > value)
	{
		if (current->leftChild == nullptr)
		{
			current->leftChild = createTemp(value);
			updateHeight(current);
			return;
		}
		addNodeValue(tree, current->leftChild, value);
		updateHeight(current);
		current = balance(current);
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

	addNodeValue(tree, tree.root, value);

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

void removeNodeValue(BinaryTree &tree, BinaryTreeNode *&child, int value)
{
	if (child->value == value)
	{
		if ((child->leftChild == nullptr) && (child->rightChild == nullptr))
		{
			delete child;
			child = nullptr;
			child = balance(child);
			return;
		}

		if ((child->leftChild != nullptr) && (child->rightChild == nullptr))
		{
			BinaryTreeNode *temp = child;

			child = child->leftChild;
			delete temp;
			child = balance(child);
			return;
		}

		if ((child->leftChild == nullptr) && (child->rightChild != nullptr))
		{
			BinaryTreeNode *temp = child;

			child =  child->rightChild;
			delete temp;
			child = balance(child);
			return;
		}

		if ((child->leftChild != nullptr) && (child->rightChild != nullptr))
		{
			child->value = findTheSmallestValueAndDestroyIt(tree, child->rightChild);
			child = balance(child);
			return;
		}
	}

	if ((child->value > value) && (child->leftChild != nullptr))
	{
		removeNodeValue(tree, child->leftChild, value);
		child = balance(child);
	}

	if ((child->value < value) && (child->rightChild != nullptr))
	{
		removeNodeValue(tree, child->rightChild, value);
		child = balance(child);
	}
	return;
}

void TreeADT::removeValue(BinaryTree &tree, int value)
{
	if (tree.root != nullptr)
		removeNodeValue(tree, tree.root, value);

	tree.root = balance(tree.root);

	return;
}

bool existNode(BinaryTree &tree, BinaryTreeNode *child, int value)
{
	if (child->value == value)
		return	true;

	if (value < child->value)
		if (child->leftChild == nullptr)
			return false;
		else
			return existNode(tree, child->leftChild, value);

	if (value > child->value)
		if (child->rightChild == nullptr)
			return false;
		else
			return existNode(tree, child->rightChild, value);
}

bool TreeADT::exist(BinaryTree &tree, int value)
{
	return existNode(tree, tree.root, value);
}

void printNodeAscennding(BinaryTree &tree, BinaryTreeNode *child)
{
	if (child != nullptr)
	{
		if (child->leftChild != nullptr)
			printNodeAscennding(tree, child->leftChild);

		printf("%d%c", child->value, ' ');

		if (child->rightChild != nullptr)
			printNodeAscennding(tree, child->rightChild);
	}

	return;
}

void TreeADT::printAscennding(BinaryTree &tree)
{
	printNodeAscennding(tree, tree.root);

	return;
}

void printNodeDescending(BinaryTree &tree, BinaryTreeNode *child)
{
	if (child != nullptr)
	{
		if (child->rightChild != nullptr)
			printNodeDescending(tree, child->rightChild);

		printf("%d%c", child->value, ' ');

		if (child->leftChild != nullptr)
			printNodeDescending(tree, child->leftChild);
	}

	return;
}

void TreeADT::printDescending(BinaryTree &tree)
{
	printNodeDescending(tree, tree.root);

	return;
}

void printSomeNodeOrder(BinaryTree &tree, BinaryTreeNode *child)
{
	printf("%c%d%c", '(', child->value, ' ');

	if (child->leftChild == nullptr)
		printf("%s", "null");
	else
		printSomeNodeOrder(tree, child->leftChild);

	printf("%c", ' ');

	if (child->rightChild == nullptr)
		printf("%s", "null");
	else
		printSomeNodeOrder(tree, child->rightChild);

	printf("%s", ")");

	return;
}

void TreeADT::printSomeOrder(BinaryTree &tree)
{
	printSomeNodeOrder(tree, tree.root);

	return;
}