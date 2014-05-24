#pragma once

#include <QString>
#include <QPair>
#include <QMap>

enum States { none, nought, cross };

class TicTacToe
{

public:
    TicTacToe();

    void init(int size);
    void setSize(int newSize);
    int getSize();

    QString getText(QPair<int, int> coordinates);
    int check();

private:
    bool isFull();
    void changePlayer();
    bool checkWin();

    int player;
    QMap <QPair<int, int>, States>  states;
    int size;
};
