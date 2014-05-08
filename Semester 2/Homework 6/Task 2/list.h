#pragma once
#include "list.h"
#include "MyError.h"
#include <iostream>

///list
class List
{
public:
    List();
    ~List();
///add value to list
    void addValue(int value);
    ///delete value from list
    void deleteValue(int value);
    ///check if there are such value in list
    bool findValue(int value) const;
    ///print list
    void print() const;
    ///return size of list
    int getSize() const;

protected:
    struct ListElement
    {
        int value;
        ListElement *next;
    };

    ListElement *head;

    int size;
};
