#include "pointerlist.h"
#include "arraylist.h"
#include <iostream>
#include "listtest.h"

using namespace std;

int main()
{
    ListTest test;
    QTest::qExec(&test);

    cout << "Welcome to the program of the lists\n";
    cout << "Enter 1 if you want add some value to the lists\nEnter 2 if you want to delete some value from lists\nEnter 3 if you want to check if there are value in lists\nEnter 4 if you want to print lists\nEnter 0 if you want to exit\n";

    List *pointerList = new PointerList();
    List *arrayList = new ArrayList();

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
            delete pointerList;
            delete arrayList;

            return 0;
        }

        case add:
        {
            cout << "Enter value ";
            int value = 0;
            cin >> value;

            pointerList->addValue(value);
            arrayList->addValue(value);

            break;
        }

        case del:
        {
            cout << "Enter value ";
            int value = 0;
            cin >> value;

            pointerList->deleteValue(value);
            arrayList->deleteValue(value);

            break;
        }

        case check:
        {
            cout << "Enter value ";
            int value = 0;
            cin >> value;

            cout << (pointerList->findValue(value) ? "There are this value in pointer list\n" : "There are not this value in pointer list\n");
            cout << (arrayList->findValue(value) ? "There are this value in array list\n" : "There are not this value in array list\n");

            break;
        }

        case print:
        {
            cout << "Pointer list: \n";
            pointerList->print();
            cout << "Array list: \n";
            arrayList->print();

            break;

        }   

        }
    }
}
