#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "hashTable.h"

using namespace std;
using namespace hashTable;

char *initString(int stringLength);

int main()
{
	fstream input("input.txt");

	if (input.is_open())
	{
		printf("%s\n", "Your file is not exist");

		system("PAUSE");
		return 0;
	}

	HashTable hashTable = createHashTable(100000);

	const int stringLength = 255;

	char *string = initString(stringLength);
	char *word = initString(stringLength);

	while (!input.eof())
	{
		input >> string;

		int i = 0;
		
		while (i < strlen(string))
		{
			int wordLength = 0;

			while ((string[i] != ' ') && (string[i] != '\n') && (string[i] != '\0'))
			{
				word[wordLength] = string[i];
				++i;
				++wordLength;
			}
			
			addToHashTable(hashTable, charToStirng(word));

			++i;
		}
	}
		
	printHashTable(hashTable);
	printf("%s%f\n", "Load factor is ", loadFactor(hashTable));
	printf("%s%d\n", "Average length of chain is ", averageLength(hashTable));
	printf("%s%d\n", "Max length of chain is ", hashTable.tableElement[maxLength(hashTable)].size);
	printf("%s\n", "Max length chain is ");
	showList(hashTable.tableElement[maxLength(hashTable)]);
	printf("%s%d\n", "Amount of words ", amount(hashTable));
	printf("%s%d\n", "Amount of empty cells is ", empty(hashTable));

	deleteHashTable(hashTable);
	delete [] string;
	delete [] word;
	
	input.close();

	system("PAUSE");
	return 0;
}

char *initString(int stringLength)
{
	char *string = new char[stringLength];

	for (int i = 0; i < stringLength; ++i)
		string[i] = '\0';

	return string;
}