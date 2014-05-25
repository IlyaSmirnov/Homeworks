#pragma once

#include <QMainWindow>
#include <QtNetwork/QtNetwork>
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

private slots:
    void sessionOpened();
    void acceptConnection();
    void startRead();
    void send();
    void disconnected();

private:
    Ui::MainWindow *ui;

    QTcpServer *tcpServer;
    QTcpSocket *clientSocket;
    QNetworkSession *networkSession;
    quint16 messegeSize;
};
