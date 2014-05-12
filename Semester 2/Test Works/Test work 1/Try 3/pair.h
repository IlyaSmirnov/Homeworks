#pragma once

class Pair
{
public:
    ///pair
    Pair();

    ///set first number
    void setFirst(int first);
    ///set second number
    void setSecond(int second);

    ///return first number
    int returnFirst();
    ///return second number
    int returnSecond();

    ///addition of pairs
    Pair operator +(Pair pair);
    ///multiplication by a constant
    Pair operator *(int number);

protected:
    int first;
    int second;
};
