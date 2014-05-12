#include "pair.h"

Pair::Pair() : first(0), second(0)
{
}

void Pair::setFirst(int first)
{
    this->first = first;
}

void Pair::setSecond(int second)
{
    this->second = second;
}

int Pair::returnFirst()
{
    return first;
}

int Pair::returnSecond()
{
    return second;
}

Pair Pair::operator +(Pair pair)
{
    Pair sum;
    sum.first = this->first + pair.first;
    sum.second = this->second + pair.second;

    return sum;
}

Pair Pair::operator *(int number)
{
    Pair mult;
    mult.first = this->first * number;
    mult.second = this->second * number;

    return mult;
}

