#include "hashTable.h"
#include <QTextStream>

using namespace std;

int main()
{
    cout << "Welcome to the program of the hash table\n";
    cout << "Enter 1 if you want add some string to table\nEnter 2 if you want to delete some value from table\nEnter 3 if you want to check if there are value in table\nEnter 4 if you want to print statisctics\nEnter 5 if you want to change hash function\nEnter 0 if you want to exit\n";

    enum userChoice { exit, add, del, check, print , change };

    userChoice choice = add;

    HashTable *hashTable = new HashTable(100000000);

    const int stringLength = 255;

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
            delete hashTable;

            return 0;
        }

        case add:
        {
            cout << "Enter string ";
            QString word;

            word.resize(stringLength);
            word.clear();

            QTextStream inp(stdin);

            inp >> word;

            hashTable->add(word);

            break;
        }

        case del:
        {
            cout << "Enter string ";
            QString word;

            word.resize(stringLength);
            word.clear();

            QTextStream inp(stdin);

            inp >> word;

            hashTable->del(word);

            break;
        }

        case check:
        {
            cout << "Enter string ";
            QString word;

            word.resize(stringLength);
            word.clear();

            QTextStream inp(stdin);

            inp >> word;

            cout << (hashTable->inTable(word) ? "There are such elements\n" : "There are not such elements\n");

            break;
        }

        case print:
        {
            printf("%s%f\n", "Load factor is ", hashTable->loadFactor());
            printf("%s%d\n", "Average length of chain is ", hashTable->averageLength());
            printf("%s%d\n", "Amount of words ", hashTable->amount());
            printf("%s%d\n", "Amount of empty cells is ", hashTable->empty());

            break;
        }

        case change:
        {
            cout << "Enter 0, if you want to calculate hash function using prime numbers or 1 if you want calculate hash function other way ";
            int value = 0;
            cin >> value;

            if ((value < 0) || (value > 1))
                cout << "incorrectly";
            else
                hashTable->changeHashFunction(value);

            break;
        }

        }
    }
}
