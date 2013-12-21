#include "binaryTree.h"
#include "sortedList.h"
#include <string.h>
#include <stdlib.h>

using namespace sortedListNS;
using namespace binaryTreeNS;
using namespace std;

char **createTable(int tableSize, SortedList list)
{
	char **table = new char *[tableSize];

	for (int i = 0; i < tableSize; ++i)
		table[i] = new char[tableSize];

	for (int i = 0; i < tableSize; ++i)
		for (int j = 0; j < tableSize; ++j)
			table[i][j] = '\0';

	return table;
}

char *createString(int stringLength)
{
	char *string = new char[stringLength];
	for (int i = 0; i < stringLength; ++i)
		string[i] = '\0';

	return string;
}

void makeTable(BinaryTreeNode *child, char **table, char *code)
{
	if ((child->leftChild == nullptr) && (child->rightChild == nullptr))
		for (unsigned int i = 0; i < strlen(code); ++i)
			table[(int) child->symbol][i] = code[i];
	else
	{
		if (child->leftChild != nullptr)
		{
			code[strlen(code)] = '0';
			makeTable(child->leftChild, table, code);
			code[strlen(code) - 1] = '\0';
		}

		if (child->rightChild != nullptr)
		{
			code[strlen(code)] = '1';
			makeTable(child->rightChild, table, code);
			code[strlen(code) - 1] = '\0';
		}
	}

	return;
}

char **createHuffmanTable(SortedList list, int tableSize)
{
	char **table = createTable(tableSize, list);

	const int stringLength = 256;
	char *code = createString(stringLength);

	makeTable(list.head->tree.root, table, code);

	delete[]code;
	code = nullptr;

	return table;
}

void deleteTable(char **&table, int tableSize)
{
	for (int i = 0; i < tableSize; ++i)
	{
		delete table[i];
		table[i] = nullptr;
	}

	delete[] table;
	table = nullptr;

	return;
}

int main()
{
	fstream input1("input.txt");

	if (!input1.is_open())
		return 0;
	
	SortedList list = createSortedList();

	while (!input1.eof())
	{
		char symbol = '0';
		input1 >> symbol;

		BinaryTree tempTree = createTempTree(nullptr, nullptr, symbol);

		if (symbol != '0')
			addValueToSortedList(list, tempTree, 1);
	}

	makeTree(list);
	
	fstream output("output.txt", ios::out);
	printTree(list.head->tree, output);

	const int tableSize = 10000;
	char **table = createHuffmanTable(list, tableSize);
		
	input1.close();
	input1.clear();
	fstream input2("input.txt");

	output << '\n';

	while (!input2.eof())
	{
		char symbol = '0';
		input2 >> symbol;

		if (symbol != '0')
			output << table[(int) symbol];
	}

	deleteSortedList(list);
	deleteTable(table, tableSize);

	input2.close();
	output.close();
	
	return 0;
}