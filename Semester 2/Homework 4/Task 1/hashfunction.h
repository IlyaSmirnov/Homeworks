#pragma once

#include <QObject>

///calcualte hashfuction which user want
class HashFunction
{
public:
    HashFunction();
    HashFunction(int value);
    int calculate(QString &string);

private:
    enum userchoice{ prime, another };
    userchoice state;
};

