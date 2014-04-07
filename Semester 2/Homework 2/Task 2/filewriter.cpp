#include "filewriter.h"

using namespace std;

bool FileWriter::write(int **array, int size) const
{
    if (size % 2 == 0)
        return false;

    fstream output("output.txt", ios::out);
    int *spiralWalk = walkOnSpiral(array, size);

    for (int i = size * size - 1; i >= 0; --i)
        output << spiralWalk[i] << ' ';

    delete [] spiralWalk;
    output.close();

    return true;
}
