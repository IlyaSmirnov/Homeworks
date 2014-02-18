#pragma once
#include "list.h"

class ArrayList : public List
{
public:
    void addValue(int value);
    void deleteValue(int value);
    bool findvalue(int value) const;
    void print() const;
    int getSize() const;

private:
    int listElements[100];
};
