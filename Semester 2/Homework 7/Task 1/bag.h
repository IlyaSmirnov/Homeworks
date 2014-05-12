#pragma once

#include <iostream>
#include <QMap>

#include "myError.h"

using namespace std;
using namespace MyError;

///Multiset
template <typename T>
class Bag
{
public:
    Bag();
    ///Add value to bag
    void add(const T& value);
    ///del value from bag
    void del(const T& value);
    ///check if there are such value in bag
    bool check(const T& value);
    ///print bag
    void print();

private:
    QMap<T, int> tree;
};

template <typename T>
Bag<T>::Bag()
{
    tree.clear();
}

template <typename T>
void Bag<T>::add(const T& value)
{
    if (check(value))
        ++tree[value];
    else
        tree.insert(value, 1);
}

template <typename T>
void Bag<T>::del(const T& value)
{
    if (tree.empty())
    {
        throw DelFromEmpty();
        return;
    }

    if (check(value))
        if (tree[value] == 1)
            tree.remove(value);
        else
            --tree[value];
    else
    {
        throw DeleteUnaddedElement();
        return;
    }
}

template <typename T>
bool Bag<T>::check(const T& value)
{
    return tree.contains(value);
}

template <typename T>
void Bag<T>::print()
{
    QMapIterator<T, int> i(tree);
    while(i.hasNext())
    {
        i.next();
        cout << i.key() << ": " << i.value() << "\n";
    }
}
