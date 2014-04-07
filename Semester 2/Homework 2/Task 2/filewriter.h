#pragma once
#include "Writer.h"
#include <fstream>

///Class which can print a matrix as a spiral bypass to file
class FileWriter : public Writer
{
public:
///Method which print a matrix as a spiral bypass to file
    bool write(int **array, int size) const;
};
