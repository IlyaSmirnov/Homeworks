#pragma once

#include "pair.h"

#include <QObject>
#include <QtTest/QtTest>

class PairTest : public QObject
{
    Q_OBJECT

public:
    explicit PairTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void SumTest()
    {
        Pair pair1;
        Pair pair2;
        pair1.setFirst(4);
        pair1.setSecond(3);
        pair2.setFirst(15);
        pair2.setSecond(7);

        pair1 = pair1 + pair2;
        QVERIFY((pair1.returnFirst() == 19) && (pair1.returnSecond() == 10));
    }

    void MultTest()
    {
        Pair pair;
        pair.setFirst(4);
        pair.setSecond(3);

        pair = pair * 5;
        QVERIFY((pair.returnFirst() == 20) && (pair.returnSecond() == 15));
    }
};
