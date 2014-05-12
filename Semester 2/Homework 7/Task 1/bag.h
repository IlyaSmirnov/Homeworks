#pragma once

#include <iostream>
#include <QMap>

using namespace std;

template <typename T>
class Bag
{
public:
    Bag();

    void add(const T& value);
    void del(const T& value);
    bool check(const T& value);
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
    if (tree.empty())
    {
        cout << "Multiset is empty" << endl;
        return;
    }

    if (check(value))
        ++tree[value];
    else
        tree.insert(value, 1);
}

template <typename T>
void Bag<T>::del(const T& value)
{
    if (check(value))
        if (tree[value] == 1)
            tree.remove(value);
        else
            --tree[value];
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
