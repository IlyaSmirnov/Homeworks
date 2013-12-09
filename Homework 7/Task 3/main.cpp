#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "hashTable.h"


using namespace std;
using namespace hashTable;

int main()
{
	fstream input("input.txt");

	if (!input.is_open())
		printf("%s\n", "Your file is not exist");
	else
	{
		HashTable hashTable = createHashTable(100000);
		const int stringLength = 255;
		char *string = new char[stringLength];
		char *word = new char[stringLength];

		for (int i = 0; i < stringLength; ++i)
		{
			string[i] = '\0';
			word[i] = '\0';
		}

		while (!input.eof())
		{
			input >> string;

			int i = 0;
			int length = strlen(string);

			while (i < length)
			{
				int wordLength = 0;

				while ((string[i] != ' ') && (string[i] != '\n') && (string[i] != '\0'))
				{
				
					word[wordLength] = string[i];
					i++;
					wordLength++;
				}

				++i;
				addToHashTable(hashTable, charToStirng(word));
			}
		}
		
		printHashTable(hashTable);
		printf("%s%L\n", "Load factor is ", loadFactor(hashTable));
		printf("%s%d\n", "Average length of chain is ", averageLength(hashTable));
		printf("%s%d\n", "Max length of chain is ", hashTable.tableElement[maxLength(hashTable)].size);
		showList(hashTable.tableElement[maxLength(hashTable)]);
		printf("%s%d\n", "Amount of words ", amount(hashTable));
		printf("%s%d\n", "Amount of empty cells is ", empty(hashTable));

		deleteHashTable(hashTable);
	}

	input.close();

	system("PAUSE");
	return 0;
}