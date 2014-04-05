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
    void plusTest()
    {
        QVERIFY((calculator->calculate(2, "+", 3) == 5));
    }

    void minusTest()
    {
        QVERIFY((calculator->calculate(2, "-", 3) == -1));
    }

    void multTest()
    {
        QVERIFY((calculator->calculate(6, "*", 7) == 42));
    }

    void divTest()
    {
        QVERIFY((calculator->calculate(4, "/", 2) == 2));
    }

private:
    Calculator *calculator = new Calculator;

};
