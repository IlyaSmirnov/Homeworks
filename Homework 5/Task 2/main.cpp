#include <stdio.h>
#include <stdlib.h>
#include <bitset>

using namespace std;

int main()
{
    double n;
    n = 0;

    printf("%s\n", "Welcome to the program which rape your float number and print it in scientific notation");

    printf("%s", "Enter a number: ");
    scanf("%lf", &n);

    unsigned char* pointer = (unsigned char*)(&n + 1);
    int bitCheck;

    --pointer;

    if (bitCheck & *pointer)
    {
        printf("%s", "Result: -");
    }
    else
    {
        printf("%s", "Result: +");
    }

    long int exponent;
    int i;

    bitCheck = 0b00010000;
    exponent = 0;
    i = 1;
    pointer--;

    while (bitCheck != 0b00000000)
    {
        if (bitCheck & *pointer)
        {
            exponent += i;
        }

        i *= 2;
        bitCheck <<= 1;
    }

    ++pointer;
    bitCheck = 0b00000001;

    while (bitCheck != 0b10000000)
    {
        if (bitCheck & * pointer)
        {
            exponent += i;
        }

        i *= 2;
        bitCheck <<= 1;
    }

    pointer--;

    double mantissa;
    double iDouble;

    mantissa = 1.0;
    bitCheck = 0b00001000;
    iDouble = 0.5;

    while (bitCheck != 0b00000000)
    {
        if (bitCheck & *pointer)
        {
            mantissa += iDouble;
        }

        iDouble /= 2;
        bitCheck >>= 1;
    }

    for (int j = 0; j < 6; ++j)
    {
        --pointer;
        bitCheck = 0b10000000;

        while (bitCheck != 0b00000000)
        {
            if (bitCheck & *pointer)
            {
                mantissa += iDouble;
            }

            iDouble /= 2;
            bitCheck >>= 1;
        }
    }

    printf("%lf%s%ld%c\n", mantissa, "*2^(", exponent + 1, ')');

    system("PAUSE");
    return 0;
}
