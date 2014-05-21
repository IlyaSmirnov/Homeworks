#pragma once

template<typename T>
class Comparator
{
public:
    Comparator() {};
    virtual ~Comparator() {};

    ///return 0 if first and second objects are equal. If they are not return 1 or -1 depends on which is bigger according comparator
    virtual int compare(T first, T second) = 0;
};
