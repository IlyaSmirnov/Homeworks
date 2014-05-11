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
        SharedPointer<int> pointer(new int(4));
        SharedPointer<int> pointer2(pointer);
        QVERIFY(pointer.getMemory() == pointer2.getMemory() && (pointer.getPointer() == pointer2.getPointer()));
    }

    void assignmentTest()
    {
        SharedPointer<int> pointer(new int(4));
        SharedPointer<int> pointer2(new int(3));
        pointer2 = pointer;
        QVERIFY(pointer.getMemory() == pointer2.getMemory() && (pointer.getPointer() == pointer2.getPointer()));
    }
};
