#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->operation->addItem("+");
    ui->operation->addItem("-");
    ui->operation->addItem("*");
    ui->operation->addItem("/");

    connect(ui->argument1, SIGNAL(valueChanged(int)), this, SLOT(editResult()));
    connect(ui->operation, SIGNAL(currentTextChanged(QString)), this, SLOT(editResult()));
    connect(ui->argument2, SIGNAL(valueChanged(int)), this, SLOT(editResult()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::editResult()
{
    if ((ui->argument2->value() == 0) && (ui->operation->currentText() == "/"))
            ui->result->setText("incorrectly");
    else
        ui->result->setText(QString::number(calculator.calculate(ui->argument1->value(), ui->operation->currentText(), ui->argument2->value())));
}
