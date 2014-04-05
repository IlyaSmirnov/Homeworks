#include "hashfunction.h"

HashFunction::HashFunction() : state(prime)
{
}

int HashFunction::calculate(QString &string)
{
    int hash = 0;
    if (state == prime)
        for (int i = 0; i < string.length(); ++i)
        {
            hash = (hash * 157  + static_cast<int>(string[i].toLatin1())) % string.length();
        }
    else
    {
        for (int i = 0; i < string.length(); ++i)
            hash += hash * 157  + static_cast<int>(string[i].toLatin1()) * i;
    }

    return hash;
}

void HashFunction::changeState(int value)
{
    if (value == 0)
        state = prime;
    else
        state = another;
}
