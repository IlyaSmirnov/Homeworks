#include "consolewriter.h"

using namespace std;

bool ConsoleWriter::write(int **array, int size) const
{
    if (size % 2 == 0)
        return false;

    int *spiralWalk = walkOnSpiral(array, size);

    for (int i = size * size - 1; i >= 0; --i)
        cout << spiralWalk[i] << ' ';

    delete [] spiralWalk;

    return true;
}
