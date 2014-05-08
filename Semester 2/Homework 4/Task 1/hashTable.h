#pragma once

#include <QStringList>
#include <iostream>
#include "hashfunction.h"

///Hashtable
class HashTable
{
public:
    HashTable(int size);
    ~HashTable();

    ///Add string to hashtable
    void add(QString &string);
    ///Delete string from hashtable
    void del(QString &string);
    ///Check string in hashtable
    bool inTable(QString &string);
    ///Change hash function
    void changeHashFunction(HashFunction *function);

    ///Calculate load factor
    double loadFactor();
    ///Calculate average length of chains
    int averageLength();
    ///Calculate amount of words
    int wordsTotal();
    ///Calculate how many empty cells left
    int emptyCells();

private:
    int hashTableSize;
    QStringList *tableElement;
    HashFunction *hashFunction;
};
