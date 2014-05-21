#pragma once

#include "comparator.h"

class IntAscendingComparator : public Comparator<int>
{
public:
    int compare(int first, int second);
};
