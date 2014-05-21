#pragma once

#include "comparator.h"

class CharComparator : public Comparator<char>
{
public:
    int compare(char first, char second);
};
