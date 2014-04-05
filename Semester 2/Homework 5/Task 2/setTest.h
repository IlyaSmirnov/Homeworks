#pragma once

#include "set.h"
#include <QObject>
#include <QtTest/QtTest>

class SetTest : public QObject
{
    Q_OBJECT

public:
    explicit SetTest(QObject *parent = 0) : QObject(parent) {}
    ~SetTest()
    {
    }

private slots:
    void  init()
    {
        set.deleteAll();
    }

    void addTest()
    {
        set.add(15);
        QVERIFY(set.check(15));
    }

    void checkUnadded()
    {
        QVERIFY(!set.check(15));
    }

    void deleteTest()
    {
        set.add(15);
        set.del(15);
        QVERIFY(!set.check(15));
    }

    void deleteUnaddedTest()
    {
        set.del(15);
    }

private:
    Set<int> set;
};

