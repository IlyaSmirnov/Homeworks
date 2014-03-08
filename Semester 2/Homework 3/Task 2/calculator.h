#pragma once
#include <QObject>

class Calculator : QObject
{
    Q_OBJECT

public:
    int calculate(int argument1, QString operation, int argument2);
};

