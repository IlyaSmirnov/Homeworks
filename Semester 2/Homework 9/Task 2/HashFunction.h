#pragma once

#include <string.h>

/**
@brief is parent class for hash functions
*/
class HashFunction
{
public:
    HashFunction(void);
    ~HashFunction(void);

    virtual int calcHash(char *text) = 0;
};

