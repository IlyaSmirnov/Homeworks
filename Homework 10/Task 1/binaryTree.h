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
	
	BinaryTree createTempTree(BinaryTreeNode *leftChild, BinaryTreeNode *rightChild, char symbol);

	void printTree(BinaryTree tree, fstream &output);
}