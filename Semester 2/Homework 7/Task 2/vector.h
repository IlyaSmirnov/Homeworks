#pragma once
#include <QVector>

///vector
template<typename T, int dim>
class Vector
{
public:
    Vector();
    Vector(T *initData);
    ///copy constructer
    Vector(const Vector &otherVector);
    ~Vector();

    ///return true if it is zero vector
    bool isZero();

    ///addition
    Vector operator +(const Vector& otherVector);
    ///subtraction
    Vector operator -(const Vector& otherVector);
    ///scalar product
    T operator *(const Vector& otherVector);
    ///equality
    bool operator ==(Vector &otherVector);

private:
    T *data;
};

template<typename T, int dim>
Vector<T, dim>::Vector() : data(new T[dim])
{
    for (int i = 0; i < dim; ++i)
        data[i] = 0;
}

template <typename T, int size>
Vector<T, size>::Vector(T *initData)
{
    data = new T[size];
    for (int i = 0; i < size; i++)
        data[i] = initData[i];
}

template <typename T, int dim>
Vector<T, dim>::Vector(const Vector &otherVector)
{
    data = new T[dim];
    for (int i = 0; i < dim; ++i)
        data[i] = otherVector.data[i];
}

template<typename T, int dim>
Vector<T, dim>::~Vector()
{
    delete[] data;
}

template <typename T, int dim>
bool Vector<T, dim>::isZero()
{
    for (int i = 0; i < dim; ++i)
        if (data[i] != 0)
            return false;

    return true;
}

template <typename T, int dim>
Vector<T, dim> Vector<T, dim>::operator +(const Vector &otherVector)
{
    Vector<T, dim> sum;
    for (int i = 0; i < dim; ++i)
        sum.data[i] = data[i] + otherVector.data[i];

    return sum;
}

template <typename T, int dim>
Vector<T, dim> Vector<T, dim>::operator -(const Vector &otherVector)
{
    Vector<T, dim> diff;
    for (int i = 0; i < dim; ++i)
        diff.data[i] = data[i] - otherVector.data[i];

    return diff;
}

template <typename T, int dim>
T Vector<T, dim>::operator *(const Vector &otherVector)
{
    T mult = 0;
    for (int i = 0; i < dim; ++i)
        mult += (data[i] * otherVector.data[i]);

    return mult;
}

template <typename T, int dim>
bool Vector<T, dim>::operator ==(Vector &otherVector)
{
  for (int i = 0; i < dim; i++)
    if (data[i] != otherVector.data[i])
      return false;

  return true;
}
