#pragma once

#include <QString>
#include <QPair>
#include <QMap>

enum States { none, nought, cross };

class TicTacToe
{

public:
    TicTacToe();

    ///initialization
    void init(int size);
    ///set size
    void setSize(int newSize);
    ///return size
    int getSize();
    ///return "O" or "X" depends on which button we consider
    QString getText(QPair<int, int> coordinates);
    ///check if game is over
    int check();

private:
    ///check if it is draw
    bool isFull();
    ///change player after turn
    void changePlayer();
    ///check if it is win
    bool checkWin();

    ///number player
    int player;
    ///keep if it is none, nought or cross on button
    QMap <QPair<int, int>, States>  states;
    ///size of field
    int size;
};
