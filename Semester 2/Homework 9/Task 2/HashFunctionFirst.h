#pragma once

#include "HashFunction.h"

class HashFunctionFirst : public HashFunction
{
public:
    HashFunctionFirst(void);
    ~HashFunctionFirst(void);

    int calcHash(char *text);
};

