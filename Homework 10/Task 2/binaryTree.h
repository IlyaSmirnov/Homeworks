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

	BinaryTree createTree(BinaryTreeNode *leftChild, BinaryTreeNode *rightChild, char symbol);
	void deleteTree(BinaryTree &tree);

	BinaryTree readTree(char *string);
}