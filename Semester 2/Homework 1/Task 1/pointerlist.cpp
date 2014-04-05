#include "pointerlist.h"
#include <iostream>

using namespace std;

PointerList::PointerList() : head(nullptr), List()
  {
}

PointerList::~PointerList()
{
    while (head != nullptr)
        {
            ListElement *temp = head->next;

            delete head;

            head = temp;
        }
}

void PointerList::addValue(int value)
{
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

void PointerList::deleteValue(int value)
{
    if (head == nullptr)
    {
        cout << "The pointer list is empty!\n";
        return;
    }

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

bool PointerList::findValue(int value) const
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

void PointerList::print() const
{
    ListElement *temp = head;

        while (temp != nullptr)
        {
            cout << temp->value << ' ';

            temp = temp->next;
        }

        cout << '\n';
}

int PointerList::getSize() const
{
    return size;
}
