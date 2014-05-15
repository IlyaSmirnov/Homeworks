#pragma once

#include "vector.h"

#include <QObject>
#include <QtTest/QtTest>

class VectorTest : public QObject
{
    Q_OBJECT

public:
    explicit VectorTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void copyConstructerTest()
    {
        int array[2] = {1, 5};
        Vector<int, 2> vector1(array);
        Vector<int, 2> vector2(vector1);

        QVERIFY(vector1 == vector2);
    }

    void zeroVectorTest()
    {
        Vector<int, 5> vector;

        QVERIFY(vector.isZero());
    }

     void additionTest()
    {
        int array1[3] = {1, 3, 5};
        Vector<int, 3> vector1(array1);

        int array2[3] = {7, 15, 16};
        Vector<int, 3> vector2(array2);

        int array3[3] = {8, 18, 21};
        Vector<int, 3> sum(array3);

        QVERIFY(vector1 + vector2 == sum);
    }

     void subtractionTest()
     {
         int array1[3] = {1, 3, 5};
         Vector<int, 3> vector1(array1);

         int array2[3] = {7, 15, 16};
         Vector<int, 3> vector2(array2);

         int array3[3] = {-6, -12, -11};
         Vector<int, 3> diff(array3);

         QVERIFY(vector1 - vector2 == diff);
     }

    void multTest()
    {
        int array1[2] = {1, 3};
        Vector<int, 2> vector1(array1);

        int array2[2] = {7, 15};
        Vector<int, 2> vector2(array2);

        QVERIFY((vector1 * vector2) == 52);
    }


};
