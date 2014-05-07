#include "uniquelist.h"

using namespace std;

UniqueList::UniqueList() :  List() {}

UniqueList::~UniqueList() {}

void UniqueList::addValue(int value)
{
    if (findValue(value))
        throw MyError::AddExist();

    ListElement *temp = new ListElement;
    temp->value = value;

    if (head != nullptr)
    {
        temp->next = head;
        head = temp;

        ++size;
    }
    else
    {
        temp->next = nullptr;
        head = temp;

        ++size;
    }
}
