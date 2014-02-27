#pragma once

///Interface which provide an opportunity to sort array with some size in some specific algorithms
class Sorter
{
public:
///Abstract method which sort array with some size in some specific algorithm
    virtual void sort(int array[], int size) = 0;
};
