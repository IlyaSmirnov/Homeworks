#pragma once

#include <QString>

class Calculator
{
public:
    Calculator();
    double calculate();
    void getArgument1(double argument1);
    void getArgument2(double argument2);
    void getOperation(QString operation);
    bool isAlreadyHaveOperation();
    bool isCalculated();
    void switchStatusOfCalculation();

private:
    double argument1;
    double argument2;
    QString operation;
    bool isOperaionChosen;
    bool calculationIsDone;
};
