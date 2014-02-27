#include "consolewriter.h"

using namespace std;

void ConsoleWriter::write(int **array, int size) const
{
    int *spiralWalk = walkOnSpiral(array, size);

    for (int i = size * size - 1; i >= 0; --i)
        cout << spiralWalk[i] << ' ';

    delete [] spiralWalk;
}
