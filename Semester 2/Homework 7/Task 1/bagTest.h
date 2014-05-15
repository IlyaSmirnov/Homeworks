#pragma once

#include "bag.h"

#include <QObject>
#include <QtTest/QtTest>

class BagTest : public QObject
{
    Q_OBJECT

public:
    explicit BagTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void addTest()
    {
        bag.add(3);
        QVERIFY(bag.check(3));
    }

    void delTest()
    {
        bag.add(4);
        bag.del(4);
        QVERIFY(!bag.check(4));
    }

private:
    Bag<int>  bag;
};
