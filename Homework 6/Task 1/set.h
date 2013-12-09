#pragma once

#include <stdio.h>
#include <stdlib.h>

namespace TreeADT
{
	struct BinaryTreeNode
	{
		int value;
		BinaryTreeNode *leftChild;
		BinaryTreeNode *rightChild;
	};

	struct BinaryTree
	{
		BinaryTreeNode *root;
	};

	BinaryTree create();
	void deleteTree(BinaryTree &tree);
	
	void addValue(BinaryTree &tree, int value);
	void removeValue(BinaryTree &tree, int value);
	
	bool exist(BinaryTree &tree, int value);
	
	void printAscennding(BinaryTree &tree);
	void printDescending(BinaryTree &tree);
	void printSomeOrder(BinaryTree &tree);
}