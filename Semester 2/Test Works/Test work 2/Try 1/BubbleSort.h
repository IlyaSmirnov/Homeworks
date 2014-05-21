#pragma once

#include "comparator.h"

template<typename T>
void sort(T array[], int size, Comparator<T> *comparator)
{
    int temp;

    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(comparator->compare(array[j], array[j + 1]) == 1)
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
