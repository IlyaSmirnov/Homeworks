#pragma once

#include <math.h>

#include "pair.h"

class ComplexPair : public Pair
{
public:
    ComplexPair();
    ///multiplication of complex numbers
    ComplexPair operator *(ComplexPair complex);
    ///calculation of modulus
    double modulus();
};
