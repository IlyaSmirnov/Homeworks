#pragma once
#include "Writer.h"
#include <fstream>

class FileWriter : public Writer
{
public:
    void write(int **array, int size);
};
