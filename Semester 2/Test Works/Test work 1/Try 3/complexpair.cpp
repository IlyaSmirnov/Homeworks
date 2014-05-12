#include "complexpair.h"

ComplexPair::ComplexPair() : Pair()
{
}

ComplexPair ComplexPair::operator *(ComplexPair complex)
{
    ComplexPair mult;

    mult.first = this->first * complex.first - this->second * complex.second;
    mult.second = this->first * complex.second + this->second * complex.first;

    return mult;
}

double ComplexPair::modulus()
{
    return sqrt(first * first + second * second);
}
