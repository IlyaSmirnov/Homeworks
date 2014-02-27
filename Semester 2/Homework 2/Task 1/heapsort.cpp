#include "heapsort.h"

void downHeap(int a[], int k, int n)
{
    bool done = false;
    int maxChild = 0;

    while ((k * 2 < n) && (!done))
    {
        if (k * 2 == n)
            maxChild = k * 2;
        else
            if (a[k * 2] > a[k * 2 + 1])
                maxChild = k * 2;
            else
                maxChild = k * 2 + 1;

        if (a[k] < a[maxChild])
        {
            int temp = a[k];
            a[k] = a[maxChild];
            a[maxChild] = temp;
            k = maxChild;
        }
        else
            done = true;

    }
}

void HeapSort::sort(int array[], int size)
{
    for (int i = ((size - 1) / 2) - 1; i >= 0; --i)
        downHeap(array, i, size - 1);

    for (int i = size - 2; i > 0; --i)
    {
        int temp = array[i];
        array[i] = array[0];
        array[0] = temp;

        downHeap(array, 0, i - 1);
    }

    return;
}
