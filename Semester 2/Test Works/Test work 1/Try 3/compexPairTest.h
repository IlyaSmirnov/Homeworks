#pragma once

#include "complexPair.h"

#include <QObject>
#include <QtTest/QtTest>

class ComplexPairTest : public QObject
{
    Q_OBJECT

public:
    explicit ComplexPairTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void multTest()
    {
        ComplexPair pair1;
        ComplexPair pair2;
        pair1.setFirst(4);
        pair1.setSecond(3);
        pair2.setFirst(15);
        pair2.setSecond(7);

        pair1 = pair1 * pair2;
        QVERIFY((pair1.returnFirst() == 39) && (pair1.returnSecond() == 73));
    }

    void modulusTest()
    {
        ComplexPair pair;
        pair.setFirst(4);
        pair.setSecond(3);

        QVERIFY(pair.modulus() == 5);
    }
};
