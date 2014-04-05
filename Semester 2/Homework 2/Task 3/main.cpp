#include <iostream>
#include "QuickSort.h"

using namespace std;
using namespace Sort;

int main()
{
    cout << "Welcome to the program of sort of matrix" << endl;

    cout << "Enter n ";
    int n = 0;
    cin >> n;

    int** matrix = new int*[n];
    int *firsLine = new int[n];

    for (int i = 0; i < n;++i)
        matrix[i] = new int[n];

    cout << "Enter matrix\n";

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            cin >> matrix[i][j];
            if (i == 0)
                firsLine[j] = matrix[i][j];
        }

    quickSort(firsLine, 0, n - 1, matrix, n);

    cout << "Sorted matrx:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }

    delete firsLine;
    for (int i = 0; i < n;++i)
        delete [] matrix[i];
    delete [] matrix;

    return 0;
}

