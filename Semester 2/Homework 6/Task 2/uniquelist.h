#pragma once
#include "list.h"

class UniqueList : public List
{
public:
    UniqueList();
    ~UniqueList();

    void addValue(int value);
};
