#include "heapsort.h"

void downHeap(int a[], int k, int n)
{
    int newElt = a[k];

    while (k <= n / 2)
    {
        int child = 2 * k;

        if ((child < n) && (a[child] < a[child + 1]))
            child++;

        if (newElt >= a[child])
            break;

        a[k] = a[child];
        k = child;
    }

    a[k] = newElt;

    return;
}

void HeapSort::sort(int array[], int size)
{
    for (int i = (size / 2) - 1; i >= 0; --i)
        downHeap(array, i, size - 1);

    for (int i = size - 1; i > 0; --i)
    {
        int temp = array[i];
        array[i] = array[0];
        array[0] = temp;

        downHeap(array, 0, i - 1);
    }

    return;
}
