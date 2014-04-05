#include "treeOfOperation.h"

enum choice { r = 0, left, right };

using namespace Tree;

OperationTreeNode *createNode(char operation, int value)
{
	OperationTreeNode *root = new OperationTreeNode;
	root->opeation = operation;
	root->value = value;
	root->leftChild = nullptr;
	root->rightChild = nullptr;

	return root;
}

void fillTree(OperationTree &tree, OperationTreeNode *&root, FILE *in, char temp)
{
	choice yourChoice;
	
	if ((temp != ' ') && (temp != '(') && (temp != ')'))
	{
		root = createNode(temp, 0);

		yourChoice = left;
	}

	while (true)
	{
		temp = fgetc(in);

		if ((temp != ' ') && (temp != '(') && (temp != ')') && (tree.root == nullptr))
		{
			root = createNode(temp, 0);

			yourChoice = left;

			continue;
		}

		if ((temp != ' ') && (temp != '(') && (temp != ')') && (yourChoice == left))
		{
			if ((temp >= '0') && (temp <= '9'))
			{
				int number = temp - '0';
				while (true)
				{
					temp = fgetc(in);

					if ((temp == ' ') || (temp == ')'))
						break;

					number = number * 10 + temp - '0';
				}
				root->leftChild = createNode(' ', number);
	
				yourChoice = right;

				continue;
			}
			else
				fillTree(tree, root->leftChild, in, temp);

			yourChoice = right;

			continue;
		}

		if ((temp != ' ') && (temp != '(') && (temp != ')') && (yourChoice == right))
		{
			if ((temp >= '0') && (temp <= '9'))
			{
				int number = temp - '0';

				while (true)
				{
					temp = fgetc(in);

					if (temp == ')')
						break;

					number = number * 10 + temp - '0';
				}
				root->rightChild = createNode(' ', number);
			
				break;
			}
			else
				fillTree(tree, root->rightChild, in, temp);
			break;
		}
	}
}

OperationTree Tree::createAndFillTree(FILE *&in)
{
	OperationTree tree;
	tree.root = nullptr;


	fillTree(tree, tree.root, in, fgetc(in));
	
	return tree;
}

void printTreeWithNodeAsArgument(OperationTree &tree, OperationTreeNode *child, FILE *&out)
{
	if (child != nullptr)
	{
		if (child->leftChild != nullptr) 
		{
			if (child->value != ' ')
				fprintf(out, "%c", '(');
			printTreeWithNodeAsArgument(tree, child->leftChild, out);
		}

		if (child->opeation == ' ')	
				fprintf(out, "%d", child->value);
		else
			fprintf(out, "%c", child->opeation);

		if (child->rightChild != nullptr)
		{	
			printTreeWithNodeAsArgument(tree, child->rightChild, out);
			if (child->value != ' ')
				fprintf(out, "%c", ')');
		}
	}	
	
	return;
}

void Tree::printTree(OperationTree &tree, FILE *&out)
{
	printTreeWithNodeAsArgument(tree, tree.root, out);

	return;
}

int calculateTreeWithNodeAsArgument(OperationTree &tree, OperationTreeNode *&child)
{
	if (child != nullptr)
	{
		if ((child->leftChild != nullptr) && (child->leftChild->opeation != ' '))
			calculateTreeWithNodeAsArgument(tree, child->leftChild);

		if (child->rightChild != nullptr)
			calculateTreeWithNodeAsArgument(tree, child->rightChild);

		if (child->opeation == '+')
			child->value = child->leftChild->value + child->rightChild->value;

		if (child->opeation == '-')
			child->value = child->leftChild->value - child->rightChild->value;

		if (child->opeation == '*')
			child->value = child->leftChild->value * child->rightChild->value;

		if (child->opeation == '/')
			child->value = child->leftChild->value / child->rightChild->value;
	}
	return child->value;
}

int Tree::calculateTree(OperationTree &tree)
{
	return calculateTreeWithNodeAsArgument(tree, tree.root);
}


void deleteTreeNodeWithNodeAsArgument(OperationTree &tree, OperationTreeNode *&child)
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

void Tree::deleteTree(OperationTree &tree)
{
	if (tree.root != nullptr)
		deleteTreeNodeWithNodeAsArgument(tree, tree.root);

	return;
}