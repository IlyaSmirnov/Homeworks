#include "uniquelist.h"
#include <iostream>
#include "listtest.h"

using namespace std;

int main()
{
    ListTest test;
    QTest::qExec(&test);

    cout << "Welcome to the program of the list\n";
    cout << "Enter 1 if you want add some value to the list\nEnter 2 if you want to delete some value from list\nEnter 3 if you want to check if there are value in list\nEnter 4 if you want to print list\nEnter 0 if you want to exit\n";

    List *list = new UniqueList();

    enum userChoice { exit, add, del, check, print };

    userChoice choice = add;

    while (true)
    {
        cout << "Enter some number ";
        int temp = 0;
        cin >> temp;
        choice = static_cast<userChoice>(temp);

        switch (choice)
        {

        case exit:
        {
            delete list;

            return 0;
        }

        case add:
        {
            cout << "Enter value ";
            int value = 0;
            cin >> value;

            list->addValue(value);

            break;
        }

        case del:
        {
            cout << "Enter value ";
            int value = 0;
            cin >> value;

            list->deleteValue(value);

            break;
        }

        case check:
        {
            cout << "Enter value ";
            int value = 0;
            cin >> value;

            cout << (list->findValue(value) ? "There are this value in list\n" : "There are not this value in list\n");

            break;
        }

        case print:
        {
            cout << "List: \n";
            list->print();

            break;

        }   

        }
    }
}
