#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QSignalMapper>
#include <QGridLayout>
#include <QMessageBox>


#include "ui_mainwindow.h"
#include "ticTacToe.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void showCongratulations(QString congratulations);

private slots:
    void createGame();
    void wasClicked();

private:
    Ui::MainWindow *ui;

    TicTacToe *ticTacToe;
    QMap <QPushButton *, QPair<int, int> > buttons;
};
