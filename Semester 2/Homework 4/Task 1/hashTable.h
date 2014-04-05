#include <QStringList>
#include <iostream>
#include "hashfunction.h"

class HashTable
{
public:
    HashTable(int size);
    ~HashTable();

    void add(QString &string);
    void del(QString &string);
    bool inTable(QString &string);
    void changeHashFunction(int value);

    double loadFactor();
    int averageLength();
    int amount();
    int empty();

private:
    int hashTableSize;
    QStringList *tableElement;
    HashFunction hashFunction;
};
