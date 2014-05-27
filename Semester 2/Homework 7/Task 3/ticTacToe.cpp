#include "ticTacToe.h"

TicTacToe::TicTacToe(): player(0)
{
}

void TicTacToe::init(int size)
{
    player = 0;

    if (!states.isEmpty())
        states.clear();

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            states[qMakePair(i, j)] = none;
}

void TicTacToe::setSize(int newSize)
{
    size = newSize;
}

int TicTacToe::getSize()
{
    return size;
}

QString TicTacToe::getText(QPair<int, int> coordinates)
{
    QString result = "";

    switch(player)
    {

    case 0:
    {
        states[coordinates] = cross;
        result = "X";

        break;
    }

    case 1:
    {
        states[coordinates] = nought;
        result = "O";

        break;
    }

    }

    return result;
}

int TicTacToe::check()
{
    if (!checkWin())
    {
        player = 1 - player;

        if (isFull())
            return 0;

        return 3;
    }

    return player + 1;
}

bool TicTacToe::isFull()
{
    for (int i = 0; i < size ; ++i)
        for (int j = 0; j < size ; ++j)
            if (states[qMakePair(i, j)] == none)
                return false;

    return true;
}

bool TicTacToe::checkWin()
{ 
    bool check = true;
    for (int i = 0; i < size - 1; ++i)
        if ((states[qMakePair(i, size - 1 - i)] == none) || (states[qMakePair(i, size - 1 - i)] != states[qMakePair(i + 1, size - 2 - i)]))
        {
            check = false;
            break;
        }

    if (check)
        return true;

    for (int i = 0; i < size; ++i)
    {
        check = true;
        for (int j = 0; j < size - 1; ++j)
            if ((states[qMakePair(i, j)] == none) || (states[qMakePair(i, j)] != states[qMakePair(i, j + 1)]))
            {
                check = false;
                break;
            }

        if (!check)
            continue;

        return true;
    }

    for (int i = 0; i < size; i++)
    {
        check = true;
        for (int j = 0; j < size - 1; ++j)
            if (states[qMakePair(j, i)] == none || states[qMakePair(j, i)] != states[qMakePair(j + 1, i)])
            {
                check = false;
                break;
            }

        if (!check)
            continue;

        return true;
    }

    check = true;
    for (int i = 0; i < size - 1; ++i)
    {
        if ((states[qMakePair(i, i)] == none) || (states[qMakePair(i, i)] != states[qMakePair(i + 1, i + 1)]))
        {
            check = false;
            break;
        }
    }

    return check;
}

