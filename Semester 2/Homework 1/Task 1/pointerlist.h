#pragma once
#include "list.h"

class PointerList : public List
{
public:
    PointerList();
    ~PointerList();

    void addValue(int value);
    void deleteValue(int value);
    bool findValue(int value) const;
    void print() const;
    int getSize() const;

private:
    struct ListElement
    {
        int value;
        ListElement *next;
    };

    ListElement *head;
};
