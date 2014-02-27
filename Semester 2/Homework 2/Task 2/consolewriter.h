#pragma once
#include "Writer.h"
#include <iostream>

///Class which can print a matrix as a spiral bypass to console
class ConsoleWriter : public Writer
{
public:
///Method which print a matrix as a spiral bypass to console
    void write(int **array, int size) const;
};
