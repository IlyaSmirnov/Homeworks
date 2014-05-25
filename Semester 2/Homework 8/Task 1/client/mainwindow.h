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
    void tryConnect();
    void displayError(QAbstractSocket::SocketError socketError);
    void sessionOpened();
    void startRead();
    void send();
    void disconnected();

    void enableAddressChange();
    void disableAddressChange();

private:
    Ui::MainWindow *ui;

    QTcpSocket *serverSocket;
    QNetworkSession *networkSession;
    quint16 messegeSize;
};
