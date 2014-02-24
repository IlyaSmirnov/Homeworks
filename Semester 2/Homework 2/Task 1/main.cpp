#include <iostream>
#include "BubbleSort.h"
#include "QuickSort.h"
#include "HeapSort.h"

using namespace std;

int main()
{
    cout << "Welcome to the program of sorting of array\n";

    cout << "Enter size of array ";
    int size = 0;
    cin >> size;

    cout << "Enter array ";
    const int maxSize = 100;
    int array1[maxSize];
    int array2[maxSize];
    int array3[maxSize];
    for (int i = 0; i < size; ++i)
    {
        cin >> array1[i];
        array2[i] = array1[i];
        array3[i] = array1[i];
    }

    Sorter *bubbleSort = new BubbleSort();
    Sorter *quickSort = new QuickSort();
    Sorter *heapSort = new HeapSort();

    bubbleSort->sort(array1, size);
    quickSort->sort(array2, size);
    heapSort->sort(array3, size);

    cout << "Sorted by bubble\n";

    for (int i = 0; i < size; ++i)
    {
        cout << array1[i] << ' ';
    }

    cout << '\n';

    cout << "Sorted by quicksort\n";

    for (int i = 0; i < size; ++i)
    {
        cout << array2[i] << ' ';
    }

    cout << '\n';

    cout << "Sorted by heapsort\n";

    for (int i = 0; i < size; ++i)
    {
        cout << array3[i] << ' ';
    }

    return 0;
}

