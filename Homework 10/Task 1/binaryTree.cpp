#include "binaryTree.h"

using namespace binaryTreeNS;
using namespace std;

BinaryTree binaryTreeNS::createTree()
{
	BinaryTree tree;
	tree.root = nullptr;

	return tree;
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
	deleteTreeNode(tree, tree.root);
	
	return;
}

void SomeOrder(BinaryTreeNode* child, fstream& out)
{
	if (child == nullptr)
		out << "null";
	else
	{
		out << "("  << "" << child->symbol << " ";
		SomeOrder(child->leftChild, out);

		out << " ";

		SomeOrder(child->rightChild, out);
		out << ")";
	}

	return;
}

void binaryTreeNS::printTreeSomeOrder(BinaryTree tree, fstream& output)
{
	SomeOrder(tree.root, output);

	return;
}