#include "arraystack.h"

using namespace std;

ArrayStack::ArrayStack()
{
    top = -1;
}

void ArrayStack::push(int value)
{
    ++top;
    stackElements[top] = value;

    return;
}

int ArrayStack::pop()
{
    --top;

    return stackElements[top + 1];
}

bool ArrayStack::isEmpty()
{
    return (top > -1);
}

void ArrayStack::print()
{
    for (int i = 0; i <= top; ++i)
        cout << stackElements[i] << ' ';

    cout << '\n';

    return;
}

void ArrayStack::deleteTop()
{
    --top;

    return;
}

int ArrayStack::takeTop()
{
    return stackElements[top];
}
