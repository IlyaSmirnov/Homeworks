#pragma once

#include "HashFunction.h"

class HashFunctionSecond : public HashFunction
{
public:
    HashFunctionSecond(void);
    ~HashFunctionSecond(void);

    int calcHash(char *text);
};

