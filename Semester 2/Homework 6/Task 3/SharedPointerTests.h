#pragma once

#include "SharedPointer.h"

#include <QObject>
#include <QtTest/QtTest>

class SharedPointerTest : public QObject
{
    Q_OBJECT

public:
    explicit SharedPointerTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void copyTest()
    {
        pointer = new SharedPointer<int>(new int(4));
        SharedPointer<int> *pointer2 = new SharedPointer<int>(pointer);
        QVERIFY(pointer == pointer2);
    }

    void assignmentTest()
    {
        SharedPointer<int> *pointer2 = new SharedPointer<int>(new int(9));
        pointer = pointer2;
        QVERIFY(pointer == pointer2);

    }

private:
    SharedPointer<int> *pointer;
};
