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
        HashTable *calculator = new HashTable(1000000);
    }

    void addTest()
    {
        table->add(QString("156"));
        QVERIFY(table->inTable(QString("156")));
    }

    void checkUnadded()
    {
        QVERIFY(!table->inTable(QString("156")));
    }

    void deleteTest()
    {
        table->add(QString("156"));
        table->del(QString("156"));
        QVERIFY(!table->inTable(QString("156")));
    }

    void deleteUnaddedTest()
    {
        table->del(QString("156"));
    }



private:
    HashTable *table = new HashTable(1000000);

};
