#include "binaryTree.h"
#include "sortedList.h"
#include <string.h>
#include <stdlib.h>

using namespace sortedListNS;
using namespace binaryTreeNS;
using namespace std;

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

char **createTable(int tableSize)
{
	char **table = new char *[tableSize];

	for (int i = 0; i < tableSize; ++i)
		table[i] = new char[tableSize];

	for (int i = 0; i < tableSize; ++i)
	for (int j = 0; j < tableSize; ++j)
		table[i][j] = '\0';

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

void initString(char *string, int stringLength)
{
	for (int i = 0; i < stringLength; ++i)
		string[i] = '\0';

	return;
}

int main()
{
	fstream input("input.txt");

	if (input.is_open())
	{
		SortedList list = createSortedList();

		fstream output("output.txt", ios::out);

		while (!input.eof())
		{
			char symbol = '0';
			input >> symbol;

			BinaryTree tempTree = createTempTree(nullptr, nullptr, symbol);

			if (symbol != '0')
				addValueToSortedList(list, tempTree, 1);

			deleteTree(tempTree);
		}
		
		makeTree(list);

		printTree(list.head->tree, output);

		const int tableSize = 10000;
		const int stringLength = 256;

		
		char **table = createTable(tableSize);

		char *string = new char[stringLength];
		initString(string, stringLength);

		makeTable(list.head->tree.root, table, string);
		
		input.close();
		input.clear();
		fstream input("input.txt");

		output << '\n';

		while (!input.eof())
		{
			char symbol = '0';
			input >> symbol;

			if (symbol != '0')
				output << table[(int) symbol];
		}

		deleteSortedList(list);
		deleteTable(table, tableSize);

		delete[]string;
		string = nullptr;

		input.close();
		output.close();
	}
	
	input.close();
	
	return 0;
}