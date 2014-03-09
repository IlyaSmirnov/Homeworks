#pragma once

#include <QMainWindow>
#include <QSignalMapper>
#include <QPushButton>
#include "calculator.h"
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Calculator calculator;

private slots:
    void clickedNumberButton(const QString &text);
    void clickedOperationButton(const QString &text);
    void clickedEqualityButton();

};
