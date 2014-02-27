#pragma once

class Writer
{
public:
    virtual void write(int **array, int size) const = 0 ;
    int *walkOnSpiral(int **array, int size) const;
};
