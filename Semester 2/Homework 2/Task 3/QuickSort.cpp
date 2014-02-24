#include "QuickSort.h"

using namespace Sort;

void swapColumn(int i, int j, int n, int **matrix)
{
    for (int k = 0; k < n; ++k)
    {
        int temp = matrix[k][i];
        matrix[k][i] = matrix[k][j];
        matrix[k][j] = temp;
    }
}

void Sort::quickSort(int* a, int l, int r, int **matrix, int n)
{
    int x = a[l + (r - l) / 2];
    int i = l;
    int j = r;

    while (i <= j)
    {
        while (a[i] < x)
            i++;

        while (a[j] > x)
            j--;

        if (i <= j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;

            swapColumn(i, j, n, matrix);
            i++;
            j--;
        }
    }

    if (i < r)
        quickSort(a, i, r, matrix, n);

    if (l < j)
        quickSort(a, l, j, matrix, n);
}



