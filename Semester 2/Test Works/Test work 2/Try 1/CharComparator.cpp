#include "charComparator.h"

int CharComparator::compare(char first, char second)
{
    if (first > second)
        return 1;
    else
        if (first < second)
            return -1;
    return 0;
}
