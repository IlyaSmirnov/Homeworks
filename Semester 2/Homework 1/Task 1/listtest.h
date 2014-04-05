#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "arraylist.h"
#include "pointerlist.h"

class ListTest : public QObject
{
    Q_OBJECT

public:
    explicit ListTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void testArrayAddValue()
    {
        arrayList->addValue(0);

        QVERIFY(arrayList->getSize() == 1);
    }

    void testArrayFindValue()
    {
        arrayList->addValue(1);
        QVERIFY((arrayList->findValue(1)) && !(arrayList->findValue(10)));
    }

    void testArrayDeleteValue()
    {
        arrayList->addValue(5);
        arrayList->deleteValue(5);
        QVERIFY(!(arrayList->findValue(5)));
    }

    void testArrayDeleteNonexistentValue()
    {
        arrayList->deleteValue(5);
    }

    void testPointerAddValue()
    {
        pointerList->addValue(5);

        QVERIFY(pointerList->getSize() == 1);
    }

    void testPointerFindValue()
    {
        arrayList->addValue(5);
        QVERIFY((pointerList->findValue(5)) && !(pointerList->findValue(0)));
    }

    void testPointerDeleteValue()
    {
        pointerList->addValue(30);
        pointerList->deleteValue(30);
        QVERIFY(!pointerList->findValue(30));
    }

    void testPointerDeleteNonexistentValue()
    {
        pointerList->deleteValue(5);
        QVERIFY(pointerList->getSize() == 0);
    }

private:
      List *pointerList = new PointerList();
      List *arrayList = new ArrayList();
};
