#pragma once

#include <QString>

///Take two argument and operation and calculate
class Calculator
{
public:
    Calculator();
    double calculate();
    ///take the first argument
    void getArgument1(double argument1);
    ///take the second argument
    void getArgument2(double argument2);
    ///take operation
    void getOperation(QString &operation);
    ///return true if class have operation which not ""
    bool isAlreadyHaveOperation();
    ///return true if calculator have calculate something
    bool isCalculated();
    ///switch status of calculation: if iteration is just done and  user want to start new one function change value of calculationIsDone to false
    void switchStatusOfCalculation();

private:
    double argument1;
    double argument2;
    QString operation;
    ///is true if class have operation which not ""
    bool isOperaionChosen;
    ///is true if iteration of calculation has done
    bool calculationIsDone;
};
