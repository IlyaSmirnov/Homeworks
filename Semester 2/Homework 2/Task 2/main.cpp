#include "consolewriter.h"
#include "filewriter.h"

using namespace std;

int main()
{
    cout << "Welcome to the programm which print your array of n^2 elements in spiral oreder\n";

    int n = 0;
    cout << "Enter n ";
    cin >> n;

    int** matrix = new int*[n];
    int *firsLine = new int[n];

    for (int i = 0; i < n;++i)
        matrix[i] = new int[n];

    cout << "Enter matrix\n";

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matrix[i][j];

    enum userChoice { console, file };
    userChoice choice = console;

    cout << "Enter 0 if you want to write matrix to the console and 1 if you want do this to file ";
    int temp = 0;
    cin >> temp;
    choice = static_cast<userChoice>(temp);

    switch (choice)
    {

    case console:
    {
        Writer *writer = new ConsoleWriter();
        writer->write(matrix, n);

        break;
    }

    case file:
    {
        Writer *writer = new FileWriter();
        writer->write(matrix, n);

        break;
    }

    }


    for (int i = 0; i < n;++i)
            delete [] matrix[i];
        delete [] matrix;

    return 0;
}
