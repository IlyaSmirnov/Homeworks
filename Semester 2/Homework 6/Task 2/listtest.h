#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "uniquelist.h"

using namespace std;

class ListTest : public QObject
{
    Q_OBJECT

public:
    explicit ListTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void testAddValue()
    {
        list.addValue(5);

        QVERIFY(list.getSize() == 1);
    }

    void testDeleteValue()
    {
        list.addValue(30);
        list.deleteValue(30);
        QVERIFY(!list.findValue(30));
    }

    void testDeleteNonexistentValue()
    {
        list.deleteValue(5);
        QVERIFY(list.getSize() == 0);
    }

    void tryAddExistException()
    {
        try
                {
                    list.addValue(0);
                    list.addValue(0);
                }
                catch(MyError::AddExist &)
                {
                    cout << "This element is already in list\n";
                }
    }

    void tryDeleteUnaddedElement()
        {
            try
            {
                list.deleteValue(5);
            }
            catch(MyError::DeleteUnaddedElement &)
            {
                cout << "There are not such element in list\n";
            }
        }

private:
      UniqueList list;
};
