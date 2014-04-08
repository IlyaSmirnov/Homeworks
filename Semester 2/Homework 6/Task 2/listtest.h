#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "uniquelist.h"

class ListTest : public QObject
{
    Q_OBJECT

public:
    explicit ListTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void testAddValue()
    {
        list.addValue(5);

        QVERIFY(list.getSize() == 1);
    }

    void testDeleteValue()
    {
        list.addValue(30);
        list.deleteValue(30);
        QVERIFY(!list.findValue(30));
    }

    void testDeleteNonexistentValue()
    {
        list.deleteValue(5);
        QVERIFY(list.getSize() == 0);
    }

private:
      UniqueList list;
};
