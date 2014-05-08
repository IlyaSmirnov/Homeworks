#include "uniquelist.h"

using namespace std;

UniqueList::UniqueList() :  List() {}

UniqueList::~UniqueList() {}

void UniqueList::addValue(int value)
{
    if (findValue(value))
        throw MyError::AddExist();

    List::addValue(value);
}
