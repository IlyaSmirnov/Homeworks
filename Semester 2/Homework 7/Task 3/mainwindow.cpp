#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->size->setValue(3);

    ticTacToe = new TicTacToe();

    createGame();

    connect(ui->playButton, SIGNAL(clicked()), this, SLOT(createGame()));

}

MainWindow::~MainWindow()
{
    delete ticTacToe;

    for (int i = 0; i < ticTacToe->getSize(); ++i)
        for (int j = 0; i < ticTacToe->getSize(); ++j)
            delete ui->buttonsLayout->itemAtPosition(i, j);

    buttons.clear();

    delete ui;
}

void MainWindow::showCongratulations(QString congratulations)
{
    QMessageBox messageBox;

    messageBox.setWindowTitle("Congratulations!");
    messageBox.setText(congratulations);

    messageBox.exec();

    createGame();
}

void MainWindow::createGame()
{
    if (!buttons.empty())
    {
        for (int i = 0; i < ticTacToe->getSize(); ++i)
            for (int j = 0; j < ticTacToe->getSize(); ++j)
                delete ui->buttonsLayout->itemAtPosition(i, j)->widget();


        buttons.clear();
    }

    ticTacToe->setSize(ui->size->value());

    for (int i = 0; i < ticTacToe->getSize(); ++i)
        for (int j = 0; j < ticTacToe->getSize(); ++j)
        {
            QPushButton *button = new QPushButton(" ", this);

            button->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
            QFont fontForButton;
            fontForButton.setPixelSize(ticTacToe->getSize() * 12);
            button->setFont(fontForButton);
            button->setText(" ");

            ui->buttonsLayout->addWidget(button, i , j);

            buttons[button] = qMakePair(i, j);

            connect(button, SIGNAL(clicked()), this, SLOT(wasClicked()));
        }


    ticTacToe->init(ticTacToe->getSize());
}

void MainWindow::wasClicked()
{
    QPushButton *button = dynamic_cast<QPushButton *> (sender());

    int i = buttons[button].first;
    int j = buttons[button].second;

    button->setText(ticTacToe->getText(qMakePair(i, j)));

    button->setEnabled(false);

    int curState = ticTacToe->check();

    switch(curState)
    {

    case 0:
    {
        showCongratulations("You can't defeat even yourself. But don't be upset. \"Failure is not the end of the world\" (c) Mr. O'Neill");

        break;
    }

    case 1:
    {
        showCongratulations("Crosses wins.");

        break;
    }

    case 2:
    {
        showCongratulations("Noughts wins.");
        break;
    }

    }
}
