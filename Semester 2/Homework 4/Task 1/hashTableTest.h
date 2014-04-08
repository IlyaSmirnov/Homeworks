#pragma once

#include "hashTable.h"
#include <QObject>
#include <QtTest/QtTest>

class HashTableTest : public QObject
{
    Q_OBJECT

public:
    explicit HashTableTest(QObject *parent = 0) : QObject(parent) {}
    ~HashTableTest()
    {
        delete table;
    }

private slots:
    void  init()
    {
        delete table;
        HashTable *table = new HashTable(1000000);
    }

    void addTest()
    {
        QString test = "156";
        table->add(test);
        QVERIFY(table->inTable(test));
    }

    void checkUnadded()
    {
        QString test = "156";
        QVERIFY(!table->inTable(test));
    }

    void deleteTest()
    {
        QString test = "156";
        table->add(test);
        table->del(test);
        QVERIFY(!table->inTable(test));
    }

    void deleteUnaddedTest()
    {
        QString test = "156";
        table->del(test);
    }



private:
    HashTable *table = new HashTable(1000000);

};
