#include "hashTable.h"

using namespace hashTable;
using namespace std;

HashTable hashTable::createHashTable(int size)
{
	HashTable hashTable;
	hashTable.size = size;
	hashTable.tableElement = new List[size];

	for (int i = 0; i < size; ++i)
		hashTable.tableElement[i] = createList();
	
	return hashTable;
}

void hashTable::deleteHashTable(HashTable &hashTable)
{
	for (int i = 0; i < hashTable.size; ++i)
		deleteList(hashTable.tableElement[i]);
	
	delete[] hashTable.tableElement;

	return;
}

int hashFunction(String string)
{
	int hash = 0;

	for (int i = 0; i < string.length; ++i)
		hash += (int) string.string[i] * i;

	return hash;
}

void hashTable::addToHashTable(HashTable &hashTable, String string)
{
	addElementToList(hashTable.tableElement[hashFunction(string)], string);

	return;
}

bool findInHashTable(HashTable hashTable, String string)
{
	int hash = hashFunction(string);

	return findInList(hashTable.tableElement[hash], string);
}

void hashTable::printHashTable(HashTable hashTable)
{
	for (int i = 0; i < hashTable.size; ++i)
		showList(hashTable.tableElement[i]);
}

double hashTable::loadFactor(HashTable hashTable)
{
	double temp = amount(hashTable) * 1.0 / hashTable.size;

	return temp;
}

int hashTable::maxLength(HashTable hashTable)
{
	List tempList = hashTable.tableElement[0];
	int number = 0;
	for (int i = 1; i < hashTable.size; ++i)
	if (tempList.size < hashTable.tableElement[i].size)
	{
		number = i;
		tempList = hashTable.tableElement[i];
	}

	return number;
}

int hashTable::averageLength(HashTable hashTable)
{
	int sum = 0;
	for (int i = 0; i < hashTable.size; i++)
		sum += hashTable.tableElement[i].size;

	return sum / (hashTable.size - empty(hashTable));
}

int hashTable::amount(HashTable hashTable)
{
	int result = 0;

	for (int i = 0; i < hashTable.size; i++)
	{
		result += hashTable.tableElement[i].size;
	}

	return result;
}

int hashTable::empty(HashTable hashTable)
{
	int result = 0;
	for (int i = 0; i < hashTable.size; i++)
	if (hashTable.tableElement[i].size == 0)
		++result;

	return result;
}