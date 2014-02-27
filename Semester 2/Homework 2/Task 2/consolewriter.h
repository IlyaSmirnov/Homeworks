#pragma once
#include "Writer.h"
#include <iostream>

class ConsoleWriter : public Writer
{
public:
    void write(int **array, int size) const;
};
