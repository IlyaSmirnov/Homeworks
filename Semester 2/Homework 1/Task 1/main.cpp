#include <pointerlist.h>
#include "arraylist.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Welcome to the program of the lists\n";
    cout << "Enter 1 if you want add some value to the lists\nEnter 2 if you want to delete some value from lists\nEnter 3 if you want to check if there are value in lists\nEnter 4 if you want to print lists\nEnter 0 if you want to exit\n";

    PointerList *pointerList = new PointerList();
    PointerList *arrayList = new PointerList();

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

            cout << (pointerList->findvalue(value) ? "There are this value in pointer list\n" : "There are not this value in pointer list\n");
            cout << (arrayList->findvalue(value) ? "There are this value in array list\n" : "There are not this value in array list\n");

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
