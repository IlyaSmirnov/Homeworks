#pragma once

#include <QObject>

///Calcualte hashfuction which user want
class HashFunction
{
public:
    HashFunction();
    int calculate(QString &string);
    void changeState(int value, HashFunction hashFunction);

private:
    enum userchoice{ prime, another };
    userchoice state;
};

