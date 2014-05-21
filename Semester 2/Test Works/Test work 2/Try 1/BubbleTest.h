#pragma once

#include "BubbleSort.h"
#include "intAscendingComparator.h"
#include "intDiscendingComparator.h"
#include "charComparator.h"

#include <QObject>
#include <QtTest/QtTest>

class BubbleTest : public QObject
{
    Q_OBJECT

public:
    explicit BubbleTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void intAscendingSort()
    {
        int array[4] = {5, 1, 3, 6};
        int size = 4;
        Comparator<int> *comp = new IntAscendingComparator();
        sort(array, size, comp);
        delete comp;
        QVERIFY(array[0] == 1 && array[1] == 3 && array[2] == 5 && array[3] == 6);
    }

    void intDiscendingSort()
    {
        int array[4] = {5, 1, 3, 6};
        int size = 4;
        Comparator<int> *comp = new IntDiscendingComparator();
        sort(array, size, comp);
        delete comp;
        QVERIFY(array[0] == 6 && array[1] == 5 && array[2] == 3 && array[3] == 1);
    }

    void charSort()
    {
        char array[4] = {'a', 'z', 'e', 'c'};
        int size = 4;
        Comparator<char> *comp = new CharComparator();
        sort(array, size, comp);
        delete comp;
        QVERIFY(array[0] == 'a' && array[1] == 'c' && array[2] == 'e' && array[3] == 'z');
    }
};
