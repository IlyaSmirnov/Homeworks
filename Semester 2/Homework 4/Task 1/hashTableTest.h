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
    void addTest()
    {
        QString test = "1";
        table->add(test);
        QVERIFY(table->inTable(test));
    }

    void checkUnadded()
    {
        QString test = "15";
        QVERIFY(!table->inTable(test));
    }

    void deleteTest()
    {
        QString test = "1";
        table->add(test);
        table->del(test);
        QVERIFY(!table->inTable(test));
    }

    void deleteUnaddedTest()
    {
        QString test = "1";
        table->del(test);
    }

private:
    HashTable *table = new HashTable(1000000);

};
