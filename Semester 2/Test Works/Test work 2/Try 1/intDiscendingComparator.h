#pragma once

#include "comparator.h"

class IntDiscendingComparator : public Comparator<int>
{
public:
    int compare(int first, int second);
};
