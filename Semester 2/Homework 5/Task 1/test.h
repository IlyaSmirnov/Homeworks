#pragma once

#include "parsetree.h"

#include <QObject>
#include <QtTest/QtTest>

class Test : public QObject
{
    Q_OBJECT

public:
    explicit Test(QObject *parent = 0) : QObject(parent) {}

private slots:
    void calculateTest()
    {
        QString result("(* 5 (+ 11 (- 2 6)))");
        QVERIFY(parser.calculate(result) == 35);
    }

    void divByZere()
    {

    }

private:
    ParseTree parser;
};
