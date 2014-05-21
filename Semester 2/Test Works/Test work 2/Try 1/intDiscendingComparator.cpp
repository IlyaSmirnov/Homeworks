#include "intDiscendingComparator.h"

int IntDiscendingComparator::compare(int first, int second)
{
    if (first < second)
        return 1;
    else
        if (first > second)
            return -1;
    return 0;
}

