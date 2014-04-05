#include "list.h"
#include "string.h"

using namespace list;
using namespace stringNS;

namespace hashTable
{
	struct HashTable
	{
		int size;
		List *tableElement;
	};

	HashTable createHashTable(int size);
	void deleteHashTable(HashTable &hashT);

	void addToHashTable(HashTable &hashTable, String string);
	
	void printHashTable(HashTable hashTable);
	double loadFactor(HashTable &hashTable);
	int maxLength(HashTable hashTable);
	int averageLength(HashTable hashTable);
	int amount(HashTable hashTable);
	int empty(HashTable hashTable);
}