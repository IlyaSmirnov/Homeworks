#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "QuickSort.h"

using namespace Sort;

class MatrixSortTest : public QObject
{
    Q_OBJECT

public:
    explicit MatrixSortTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void quickTest()
    {
        int** matrix = new int*[2];
        for (int i = 0; i < 2;++i)
            matrix[i] = new int[2];

        int *firsLine = new int[2];

        matrix[0][0] = 5;
        matrix[0][1] = 3;
        matrix[1][0] = 1;
        matrix[1][1] = 2;

        firsLine[0] = 5;
        firsLine[1] = 3;

        quickSort(firsLine, 0, 1, matrix, 2);
        QVERIFY((matrix[0][0] == 3) && (matrix[0][1] == 5) && (matrix[1][0] == 2) && (matrix[1][1] == 1));
    }

};
