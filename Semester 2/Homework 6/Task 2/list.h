#pragma once
#include "list.h"
#include "MyError.h"
#include <iostream>

class List
{
public:
    List();
    ~List();

    void addValue(int value);
    void deleteValue(int value);
    bool findValue(int value) const;
    void print() const;
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
