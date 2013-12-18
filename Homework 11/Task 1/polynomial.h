#pragma once
#include "iostream"
#include "math.h"

#include <stdio.h>
#include <stdlib.h>

namespace polynomialNS
{
        struct PolynomialElement
        {
                int degree;
                int coefficient;
                PolynomialElement *next;
        };

        struct Polynomial
        {
                PolynomialElement *first;
        };

        Polynomial createPolynomial();
        void deletePolynomial(Polynomial &polynomial);

        void addToPolynimial(Polynomial &polynomial, int degree, int coefficient);
        void showPolynomial(Polynomial polynomial);

        bool equals(Polynomial p, Polynomial q);
        int value(Polynomial p, int x);
        void add(Polynomial p, Polynomial q, Polynomial &r);
}