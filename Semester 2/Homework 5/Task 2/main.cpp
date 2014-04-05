#include <iostream>
#include "setTest.h"
#include <QTextStream>
#include <QString>

using namespace std;

int main()
{
    SetTest test;
    QTest::qExec(&test);

    cout << "Welcome to the program of the int set\n";
    cout << "Enter 1 if you want add some number to set\nEnter 2 if you want to delete some number from set\nEnter 3 if you want to check if there are number in set\nEnter 4 if you want to print set\nEnter 5 if you want create union\nEnter 6 it you want create intersection\nEnter 0 if you want to exit\n";

    enum userChoice { exit, add, del, check, print, uni , inter };

    userChoice choice = add;

    Set<int> set;

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

            set.add(value);

            break;
        }

        case del:
        {
            cout << "Enter value ";
            int value = 0;

            cin >> value;

            set.del(value);

            break;
        }

        case check:
        {
            cout << "Enter value ";
            int value = 0;

            cin >> value;

            cout << (set.check(value) ? "There are such element\n" : "There are not such element\n");

            break;
        }

        case print:
        {
            set.print();

            break;
        }

        case uni:
        {
            cout << "Enter values of second set. Enter show to print union\n";

            Set<int> secondSet;

            QString word;

            word.resize(255);
            word.clear();

            QTextStream inp(stdin);
            inp >> word;
            while (true)
            {
                word.clear();
                inp >> word;
                if (word == "show")
                    break;

                secondSet.add(word.toInt());
            }

            set.createUnion(secondSet).print();

            break;
        }

        case inter:
        {
            cout << "Enter values of second set. Enter show to print union\n";

            Set<int> secondSet;

            QString word;

            word.resize(255);
            word.clear();

            QTextStream inp(stdin);
            inp >> word;
            while (true)
            {
                word.clear();
                inp >> word;
                if (word == "show")
                    break;

                secondSet.add(word.toInt());
            }

            set.createIntersection(secondSet).print();

            break;
        }

        }
    }
}

