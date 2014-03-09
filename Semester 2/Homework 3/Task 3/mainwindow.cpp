#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSignalMapper *numberMapper = new QSignalMapper(this);
    connect(numberMapper, SIGNAL(mapped(const QString &)), this, SLOT(clickedNumberButton(const QString &)));

    for (int i = 0; i <= 9; ++i)
    {
        QPushButton *button = new QPushButton(QString::number(i));
        connect(button, SIGNAL(clicked()), numberMapper, SLOT(map()));
        numberMapper->setMapping(button, QString::number(i));
        if (i == 0)
            ui->gridLayout_2->addWidget(button, 5, 0);
        else
            ui->gridLayout_2->addWidget(button, ((i - 1) / 3) + 2, ((i - 1) % 3));
    }

    ui->result->setText("0");

    QPushButton *buttonDot = new QPushButton(".");
    connect(buttonDot, SIGNAL(clicked()), numberMapper, SLOT(map()));
    numberMapper->setMapping(buttonDot, ".");
    ui->gridLayout_2->addWidget(buttonDot, 5, 1);

    QSignalMapper *operationMapper = new QSignalMapper(this);
    connect(operationMapper, SIGNAL(mapped(const QString &)), this, SLOT(clickedOperationButton(const QString &)));

    QPushButton *buttonEquality = new QPushButton("=");
    connect(buttonEquality, SIGNAL(clicked()), this, SLOT(clickedEqualityButton()));
    ui->gridLayout_2->addWidget(buttonEquality, 5, 2);

    for (int i = 0; i <= 3; ++i)
    {
        QString *oper = new QString();

        if (i == 0)
            oper[0] = '+';
        else if (i == 1)
            oper[0] = '-';
        else if (i == 2)
            oper[0] = '*';
        else
            oper[0] = '/';

        QPushButton *button = new QPushButton(*oper);
        connect(button, SIGNAL(clicked()), operationMapper, SLOT(map()));
        operationMapper->setMapping(button, *oper);
        ui->gridLayout_2->addWidget(button, i + 2, 3);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clickedNumberButton(const QString &text)
{
    if (calculator.isCalculated())
    {
        ui->result->clear();
        calculator.switchStatusOfCalculation();
    }

    if ((ui->result->text() == "Incorrectly") || ((ui->result->text()[0] == '0') && (text != ".") && ((ui->result->text()[1] != '.'))))
        ui->result->clear();

    if (text == ".")
        for (int i = 0; i < ui->result->maxLength(); ++i)
            if (ui->result->text()[i] == '.')
            {
                ui->result->setText("Incorrectly");
                return;
            }

    if ((ui->result->text() == "") && (text == "."))
        ui->result->setText("0" + text);
    else
        ui->result->setText(ui->result->text() + text);
}

void MainWindow::clickedOperationButton(const QString &text)
{
    if ((calculator.isAlreadyHaveOperation()) || (calculator.isCalculated()))
    {
        QMessageBox::warning(this, "Warning", "Enter the argument! Stop clicking on inappropriate buttons!", QMessageBox::Ok);
        return;
    }

    calculator.getArgument1(ui->result->text().toDouble());
    calculator.getOperation(text);

    ui->result->setText("0");
}

void MainWindow::clickedEqualityButton()
{
    if (calculator.isCalculated())
    {
        QMessageBox::warning(this, "Warning", "Enter the argument! Stop clicking on inappropriate buttons", QMessageBox::Ok);
        return;
    }

    calculator.getArgument2(ui->result->text().toDouble());
    if (calculator.calculate() == -666)
    {
        ui->result->setText("Incorrectly");
    }
    else
    ui->result->setText(QString::number(calculator.calculate()));
}
