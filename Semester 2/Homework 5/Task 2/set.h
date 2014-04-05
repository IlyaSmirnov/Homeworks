#pragma once

#include <iostream>
#include <QList>

using namespace std;

///set
template <typename T>
class Set
{
public:
    Set();
    ~Set();
    ///add element to set
    void add(T value);
    ///delete element from set
    void del(T value);
    ///check if there such element in set
    bool check(T value) const;
    ///create uniun of two sets
    Set createUnion(Set<T> set) const;
    ///create intersection of two sets
    Set createIntersection(Set<T> set) const;
    ///print
    void print() const;
    ///delete all
    void deleteAll();

private:
    QList<T> list;
};

template <typename T>
Set<T>::Set()
{
}

template <typename T>
Set<T>::~Set()
{
}

template <typename T>
void Set<T>::add(T value)
{
    if (!list.contains(value))
        list.push_back(value);
}

template <typename T>
void Set<T>::del(T value)
{
    if (!check(value))
    {
        cout << "There are no such element\n";
        return;
    }

    list.removeOne(value);

}

template <typename T>
bool Set<T>::check(T value) const
{
    return list.contains(value);
}

template <typename T>
Set<T> Set<T>::createUnion(Set<T> set) const
{
    Set<T> un;
    for (int i = 0; i < list.size(); ++i)
        un.add(list[i]);

    for (int i = 0; i < set.list.size(); ++i)
        if(!un.check(set.list[i]))
            un.add(set.list[i]);
    return un;
}

template <typename T>
Set<T> Set<T>::createIntersection(Set<T> set) const
{
    Set<T> intersection;

    for (int i = 0; i < list.size(); ++i)
        if (set.check(list[i]))
            intersection.add(list[i]);

    return intersection;
}

template <typename T>
void Set<T>::print() const
{
    for (int i = 0; i < list.size(); ++i)
        cout << list[i] << " ";
    cout << '\n';
}

template <typename T>
void Set<T>::deleteAll()
{
    list.clear();
}
