#pragma once
#include "list.h"
#include "MyError.h"

class UniqueList : public List
{
public:
    UniqueList();
    ~UniqueList();

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
