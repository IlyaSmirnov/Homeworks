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
    SharedPointer(SharedPointer *sharedPointer);
    ///Operator = overloading
    SharedPointer &operator = (SharedPointer &sharedPointer);
    ///Operator == overloading
    bool operator == (SharedPointer &sharedPointer);

    ///Get memory
    int getMemory();
    ///Get pointer
    T *getPointer();

private:
    Pointer<T> *pointer;
    int memory;
};

template<typename T>
SharedPointer<T>::SharedPointer() : memory(0)
{
}

template<typename T>
SharedPointer<T>::SharedPointer(T *pointer) : pointer(new Pointer<T>(pointer)), memory(1)
{

}

template<typename T>
SharedPointer<T>::~SharedPointer()
{
    --memory;
    if (memory == 0)
        delete pointer;
}

template<typename T>
SharedPointer<T>::SharedPointer(SharedPointer *sharedPointer) : pointer(sharedPointer->pointer), memory(sharedPointer->memory)
{
}

template<typename T>
SharedPointer<T> &SharedPointer<T>::operator = (SharedPointer<T> &sharedPointer)
{
    --memory;
    if (memory == 0)
        delete pointer;

    pointer = sharedPointer.pointer;
    ++memory;
    return *this;
}

template<typename T>
int SharedPointer<T>::getMemory()
{
    return memory;
}

template<typename T>
T *SharedPointer<T>::getPointer()
{
    return pointer->pointer;
}
