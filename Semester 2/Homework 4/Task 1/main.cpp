#include "hashTable.h"
#include <QTextStream>
#include "hashTableTest.h"

using namespace std;

int main()
{
    HashTableTest test;
    QTest::qExec(&test);

    cout << "Welcome to the program of the hash table\n";
    cout << "Enter 1 if you want add some string to table\nEnter 2 if you want to delete some value from table\nEnter 3 if you want to check if there are value in table\nEnter 4 if you want to print statisctics\nEnter 5 if you want to change hash function\nEnter 0 if you want to exit\n";

    enum userChoice { exit, add, del, check, print , change };

    userChoice choice = add;

    HashTable *hashTable = new HashTable(10000);

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

            QTextStream input(stdin);

            input >> word;

            hashTable->add(word);

            break;
        }

        case del:
        {
            cout << "Enter string ";
            QString word;

            word.resize(stringLength);
            word.clear();

            QTextStream input(stdin);

            input >> word;

            hashTable->del(word);

            break;
        }

        case check:
        {
            cout << "Enter string ";
            QString word;

            word.resize(stringLength);
            word.clear();

            QTextStream input(stdin);

            input >> word;

            cout << (hashTable->inTable(word) ? "There are such elements\n" : "There are not such elements\n");

            break;
        }

        case print:
        {
            cout << "Load factor is " << hashTable->loadFactor() << endl;
            cout << "Average length of chain is " << hashTable->averageLength() << endl;
            cout << "Amount of words " << hashTable->wordsTotal() << endl;
            cout << "Amount of empty cells is " << hashTable->emptyCells() << endl;

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
                hashTable->changeHashFunction(new HashFunction(value));

            break;
        }

        }
    }
}
