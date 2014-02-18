#include "hashTable.h"
#include <fstream>

using namespace hashTable;
using namespace std;

int main()
{
	const int stringLength = 255;
	const int hashTableSize = 100000;

	fstream input1("input1.txt");
	fstream input2("input2.txt");
	
	if ((input1.is_open()) && (input2.is_open()))
	{
		fstream output("output.txt");
		HashTable hashTable = createHashTable(hashTableSize);
		String string = createString(stringLength);
	
		while (!input1.eof())
		{
			input1.getline(string.string, stringLength);
			
			addToHashTable(hashTable, string);
		}

		while (!input2.eof())
		{
			input2.getline(string.string, stringLength);
			
			if (findInHashTable(hashTable, string))
				output << string.string << "\n";
		}	

		deleteString(string);
		deleteHashTable(hashTable);
		output.close();
	}

	input1.close();
	input2.close();

	return 0;
}