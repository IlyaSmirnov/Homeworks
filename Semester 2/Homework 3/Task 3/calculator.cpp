#include "calculator.h"

Calculator::Calculator() : argument1(0), argument2(0), operation(""), isOperaionChosen(false), calculationIsDone(false)
{
}

double Calculator::calculate()
{
    isOperaionChosen = false;
    calculationIsDone = true;

    switch (static_cast<char>(operation.toStdString()[0]))
        {

        case '+':
        {
            return argument1 + argument2;
        }

        case '-':
        {
            return argument1 - argument2;
        }

        case '*':
        {
            return argument1 * argument2;
        }


        case '/':
        {
            if (argument2 == 0)
                return -666;

            return argument1 / argument2;
        }

       }
}

void Calculator::setArgument1(double argument1)
{
    this->argument1 = argument1;
}

void Calculator::setArgument2(double argument2)
{
    this->argument2 = argument2;
}

void Calculator::setOperation(const QString &operation)
{
    isOperaionChosen = true;
    this->operation = operation;
}

bool Calculator::isAlreadyHaveOperation()
{
    return isOperaionChosen;
}

bool Calculator::isCalculated()
{
    return calculationIsDone;
}

void Calculator::switchStatusOfCalculation()
{
    calculationIsDone = false;
}
