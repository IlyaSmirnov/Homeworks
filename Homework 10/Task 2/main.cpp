#include "binaryTree.h"

using namespace binaryTreeNS;
using namespace std;

void decode(fstream &input, BinaryTree tree)
{
	fstream output("output.txt", ios::out);

	BinaryTreeNode *currentChild = tree.root;
	char symbol = '0';

	while (!input.eof())
	{
		if (currentChild->symbol != '0')
		{
			output << currentChild->symbol;
			currentChild = tree.root;

			continue;
		}

		input >> symbol;

		if ((symbol == '0'))
		{
			currentChild = currentChild->leftChild;

			continue;
		}

		if (symbol == '1')
		{
			currentChild = currentChild->rightChild;

			continue;
		}
	}

	deleteTree(tree);
	output.close();
}

char *readLine(fstream &input)
{
	const int stringLength = 256;
	
	char *string = new char[stringLength];
	for (unsigned int i = 0; i < stringLength; ++i)
		string[i] = '\0';

	input.getline(string, stringLength);

	return string;
}

int main()
{
	fstream input("input.txt");

	if (!input.is_open())
		return 0;

	decode(input, readTree(readLine(input)));

	input.close();
	return 0;
}