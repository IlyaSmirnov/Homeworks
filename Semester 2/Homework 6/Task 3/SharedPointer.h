#pragma once

#include "pointer.h"

template<typename T>
class SharedPointer
{
public:
    SharedPointer();
    SharedPointer(T *pointer);
    ~SharedPointer();

    ///Copy constructor
    SharedPointer(SharedPointer const &sharedPointer);
    ///Operator = overloading
    SharedPointer &operator =(SharedPointer const &sharedPointer);

    ///Get memory
    int getMemory();
    ///Get pointer
    T *getPointer();

private:
    Pointer<T> *pointer;
};

template<typename T>
SharedPointer<T>::SharedPointer()
{
    pointer->memory = 0;
    pointer->pointer = nullptr;
}

template<typename T>
SharedPointer<T>::SharedPointer(T *pointer) : pointer(new Pointer<T>(pointer))
{
    this->pointer->memory = 1;
}

template<typename T>
SharedPointer<T>::~SharedPointer()
{
    --pointer->memory;
    if (pointer->memory == 0)
        delete pointer;
}

template<typename T>
SharedPointer<T>::SharedPointer(SharedPointer const &sharedPointer) : pointer(sharedPointer.pointer)
{
    pointer = sharedPointer.pointer;
    ++pointer->memory;
}

template<typename T>
SharedPointer<T> &SharedPointer<T>::operator =(SharedPointer<T> const &sharedPointer)
{
    --pointer->memory;
    if (pointer->memory == 0)
        delete pointer;

    pointer = sharedPointer.pointer;
    ++pointer->memory;
    return *this;
}

template<typename T>
int SharedPointer<T>::getMemory()
{
    return pointer->memory;
}

template<typename T>
T *SharedPointer<T>::getPointer()
{
    return pointer->pointer;
}
