#include "calculator.h"

int Calculator::calculate(int argument1, QString operation, int argument2)
{
    switch (static_cast<char>(operation.toStdString()[0]))
    {

    case '+':
    {
        return argument1 + argument2;
        break;
    }

    case '-':
    {
        return argument1 - argument2;
        break;
    }

    case '*':
    {
        return argument1 * argument2;
        break;
    }


    case '/':
    {
        return argument1 / argument2;
        break;
    }

   }

}
