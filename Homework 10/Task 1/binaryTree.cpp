#include "binaryTree.h"

using namespace binaryTreeNS;
using namespace std;

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

void print(BinaryTreeNode *child, fstream &output)
{
	if (child == nullptr)
		output << "null";
	else
	{
		output << "(" << "" << child->symbol << " ";
		print(child->leftChild, output);

		output << " ";

		print(child->rightChild, output);
		output << ")";
	}

	return;
}

BinaryTree binaryTreeNS::createTree()
{
	BinaryTree tree;
	tree.root = nullptr;

	return tree;
}

void binaryTreeNS::deleteTree(BinaryTree &tree)
{
	deleteTreeNode(tree, tree.root);
	
	return;
}

BinaryTree binaryTreeNS::createTempTree(BinaryTreeNode *leftChild, BinaryTreeNode *rightChild, char symbol)
{
	BinaryTree tree = createTree();
	tree.root = new BinaryTreeNode;

	tree.root->leftChild = leftChild;
	tree.root->rightChild = rightChild;
	tree.root->symbol = symbol;

	return tree;
}

void binaryTreeNS::printTree(BinaryTree tree, fstream& output)
{
	print(tree.root, output);

	return;
}