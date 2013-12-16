#pragma once
#include <fstream>

using namespace std;

namespace binaryTreeNS
{
	struct BinaryTreeNode
	{
		char symbol;
		BinaryTreeNode *leftChild;
		BinaryTreeNode *rightChild;
	};

	struct BinaryTree
	{
		BinaryTreeNode *root;
	};

	BinaryTree createTree();
	void deleteTree(BinaryTree &tree);
	
	void printTreeSomeOrder(BinaryTree tree, fstream& output);
}