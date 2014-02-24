#include "consolewriter.h"

using namespace std;

void ConsoleWriter::write(int **array, int size)
{
    int *array1 = new int[size * size - 1];
    int i1 = size;
    int j1 = size;
    int temp = 0;
    int j = size - j1;

    while (j < j1)
    {
        int i = size - i1;
        j = size - j1;
        for (; j < j1; j++)
        {
                array1[temp] = array[i][j];
                temp++;
        }

        j--;

        for (i++; i < i1; i++)
        {
            array1[temp] = array[i][j];
            temp++;
        }

        i--;

        for (j--; j >= size - j1; j--)
        {
            array1[temp] = array[i][j];
            temp++;
        }

        j++;

        for (i--; i > size - j1; i--)
        {
            array1[temp] = array[i][j];
            temp++;
        }

        i++;
        i1--;
        j1--;
    }

    for (int i = size * size - 1; i >= 0; i--)
        cout << array1[i] << ' ';

    delete [] array1;
}
