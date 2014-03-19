#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "heapsort.h"
#include "bubblesort.h"
#include "quicksort.h"

class SorterTest : public QObject
{
    Q_OBJECT

public:
    explicit SorterTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void quickTest()
    {
        int array[5];
        array[0] = 1;
        array[1] = 100;
        array[2] = 9;
        array[3] = 7;
        array[4] = 13;
        quick->sort(array, 5);
        QVERIFY((array[0] == 1) && (array[1] == 7) && (array[2] == 9) && (array[3] == 13) && (array[4] == 100));
    }

    void heapTest()
    {
        int array[5];
        array[0] = 1;
        array[1] = 100;
        array[2] = 9;
        array[3] = 7;
        array[4] = 13;
        heap->sort(array, 5);
        QVERIFY((array[0] == 1) && (array[1] == 7) && (array[2] == 9) && (array[3] == 13) && (array[4] == 100));
    }

    void bubbleTest()
    {
        int array[5];
        array[0] = 1;
        array[1] = 100;
        array[2] = 9;
        array[3] = 7;
        array[4] = 13;
        bubble->sort(array, 5);
        QVERIFY((array[0] == 1) && (array[1] == 7) && (array[2] == 9) && (array[3] == 13) && (array[4] == 100));
    }

private:
      Sorter *heap = new HeapSort();
      Sorter *bubble = new BubbleSort();
      Sorter *quick = new QuickSort();
};
