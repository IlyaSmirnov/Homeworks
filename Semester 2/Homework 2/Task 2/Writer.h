#pragma once

///Class which can print a matrix as a spiral bypass
class Writer
{
public:
    ///Method which print an array
    virtual bool write(int **array, int size) const = 0;
    ///Method which transform matrix to array in which elements located like spiral
    int *walkOnSpiral(int **array, int size) const;
};
