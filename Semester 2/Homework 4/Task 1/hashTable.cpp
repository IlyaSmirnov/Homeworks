#include "hashTable.h"

using namespace std;

HashTable::HashTable(int size) : hashTableSize(size)
{
    hashFunction = new HashFunction();
    tableElement = new QStringList[size];
}

HashTable::~HashTable()
{
    delete [] tableElement;
    delete hashFunction;
}

void HashTable::add(QString &string)
{
    if (inTable(string))
        return;
    tableElement[hashFunction->calculate(string)].append(string);
}

void HashTable::del(QString &string)
{
    if(!inTable(string))
    {
        cout << "There are no such element\n";
        return;
    }

    tableElement[hashFunction->calculate(string)].removeOne(string);
}

bool HashTable::inTable(QString &string)
{
    return tableElement[hashFunction->calculate(string)].contains(string);
}

void HashTable::changeHashFunction(HashFunction *function)
{
    HashFunction *temp = hashFunction;
    hashFunction = function;
    delete temp;
}

double HashTable::loadFactor()
{
    double temp = wordsTotal() * 1.0 / hashTableSize;

    return temp;
}

int HashTable::averageLength()
{
    if (wordsTotal() == 0)
        return 0;

    int sum = 0;
    for (int i = 0; i < hashTableSize; i++)
        sum += tableElement[i].size();

    return sum / (hashTableSize - emptyCells());
}

int HashTable::wordsTotal()
{
    int result = 0;

    for (int i = 0; i < hashTableSize; i++)
    {
        result += tableElement[i].size();
    }

    return result;
}

int HashTable::emptyCells()
{
    int result = 0;
    for (int i = 0; i < hashTableSize; i++)
        if (tableElement[i].size() == 0)
            ++result;

    return result;
}
