#include "uniquelist.h"
#include <iostream>

using namespace std;

UniqueList::UniqueList() : head(nullptr), List()
  {
}

UniqueList::~UniqueList()
{
    while (head != nullptr)
        {
            ListElement *temp = head->next;

            delete head;

            head = temp;
        }
}

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

void UniqueList::deleteValue(int value)
{
    if (head == nullptr)
        throw MyError::DeleteFromEmpty();

    if (value == head->value)
    {
        ListElement *temp = head;
        head = head->next;

        delete temp;

        --size;
        return;
    }

    ListElement *counter = head;

    while ((counter->next != nullptr) && (counter->next->value != value))
            counter = counter->next;

    if (counter->next == nullptr)
    {
        cout << "There are not such element in poiner list!\n";
        return;
    }

    ListElement *temp = counter->next;
    counter->next = counter->next->next;
    delete temp;
    --size;
}

bool UniqueList::findValue(int value) const
{
    ListElement *temp = head;
    while (temp != nullptr)
    {
        if (temp->value == value)
            return true;

        temp = temp->next;
    }

    return false;
}

void UniqueList::print() const
{
    ListElement *temp = head;

        while (temp != nullptr)
        {
            cout << temp->value << ' ';

            temp = temp->next;
        }

        cout << '\n';
}

int UniqueList::getSize() const
{
    return size;
}
