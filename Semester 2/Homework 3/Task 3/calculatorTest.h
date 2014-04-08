#pragma once

#include <QObject>
#include <QtTest/QtTest>
#include "calculator.h"

class calculatorTest : public QObject
{
    Q_OBJECT

public:
    explicit calculatorTest(QObject *parent = 0) : QObject(parent) {}
    ~calculatorTest()
    {
        delete calculator;
    }

private slots:
    void  init()
    {
        delete calculator;
        Calculator *calculator = new Calculator;
    }

    void plusTest()
    {
        calculator->setArgument1(2);
        calculator->setArgument2(3);
        calculator->setOperation("+");
        QVERIFY((calculator->calculate() == 5));
    }

    void minusTest()
    {
        calculator->setArgument1(2);
        calculator->setArgument2(3);
        calculator->setOperation("-");
        QVERIFY((calculator->calculate() == -1));
    }

    void multTest()
    {
        calculator->setArgument1(6);
        calculator->setArgument2(7);
        calculator->setOperation("*");
        QVERIFY((calculator->calculate() == 42));
    }

    void divTest()
    {
        calculator->setArgument1(4);
        calculator->setArgument2(2);
        calculator->setOperation("/");
        QVERIFY((calculator->calculate() == 2));
    }

private:
    Calculator *calculator = new Calculator;

};
