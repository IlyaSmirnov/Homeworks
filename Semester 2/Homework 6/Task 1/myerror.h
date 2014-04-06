#pragma once

#include <iostream>

class MyError
{
public:
    class Exception1{};

    static void throwException1()
    {
        throw Exception1();
    };
};
