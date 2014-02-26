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
    if (size == 0)
    {
        cout << "The array list is empty!\n";
        return;
    }

    int i = 0;
    while ((i < size) && (listElements[i] != value))
        ++i;

    if (size == i)
    {
        cout << "There are not such element in array list!\n";

        return;
    }


    for (int j = i; j < size - 1; ++j)
        listElements[j] = listElements[j + 1];

    --size;
}

bool ArrayList::findValue(int value) const
{
    for (int i = 0; i < size; ++i)
        if (listElements[i] == value)
            return true;

    return false;
}

void ArrayList::print() const
{
    for (int i = size - 1; i >= 0; --i)
        cout << listElements[i] << ' ';
    cout << '\n';
}

int ArrayList::getSize() const
{
    return size;
}
