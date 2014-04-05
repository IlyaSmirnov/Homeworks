#pragma once

#include <stdio.h>
#include <stdlib.h>

namespace Tree
{
	struct OperationTreeNode
	{
		int value;
		char opeation;
		OperationTreeNode *leftChild;
		OperationTreeNode *rightChild;
	};

	struct OperationTree
	{
		OperationTreeNode *root;
	};

	OperationTree createAndFillTree(FILE *&in);
	void printTree(OperationTree &tree, FILE *&out);
	int calculateTree(OperationTree &tree);
	void deleteTree(OperationTree &tree);
}