#include "arraylist.h"
#include <iostream>

using namespace std;

void ArrayList::addValue(int value)
{
    ++size;
    listElements[size - 1] = value;
}

void ArrayList::deleteValue(int value)
{
    int i = 0;
    while ((listElements[i] != value) && (i < size))
        ++i;

    if ((size - 1 == i) && ((listElements[i] != value)))
        return;

    --size;

    for (int j = i; j < size; ++j)
        listElements[j] = listElements[j + 1];
}

bool ArrayList::findvalue(int value) const
{
    for (int i = 0; i < size; ++i)
        if (listElements[i] == value)
            return true;

    return false;
}

void ArrayList::print() const
{
    for (int i = 0; i < size; ++i)
        cout << listElements[i] << ' ';
    cout << '\n';


    return;
}

int ArrayList::getSize() const
{
    return size;
}
