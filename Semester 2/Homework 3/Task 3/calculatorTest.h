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
        calculator->getArgument1(2);
        calculator->getArgument2(3);
        calculator->getOperation("+");
        QVERIFY((calculator->calculate() == 5));
    }

    void minusTest()
    {
        calculator->getArgument1(2);
        calculator->getArgument2(3);
        calculator->getOperation("-");
        QVERIFY((calculator->calculate() == -1));
    }

    void multTest()
    {
        calculator->getArgument1(6);
        calculator->getArgument2(7);
        calculator->getOperation("*");
        QVERIFY((calculator->calculate() == 42));
    }

    void divTest()
    {
        calculator->getArgument1(4);
        calculator->getArgument2(2);
        calculator->getOperation("/");
        QVERIFY((calculator->calculate() == 2));
    }

private:
    Calculator *calculator = new Calculator;

};
