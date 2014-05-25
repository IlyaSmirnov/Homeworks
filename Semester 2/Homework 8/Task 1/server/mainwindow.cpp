#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    tcpServer(0),
    clientSocket(0),
    networkSession(0),
    messegeSize(0)
{
    ui->setupUi(this);

    setWindowTitle("Server");

    ui->chatTextEdit->setReadOnly(true);
    ui->messegeLineEdit->setEnabled(false);

    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired)
    {
        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
        settings.endGroup();

        QNetworkConfiguration config = manager.configurationFromIdentifier(id);
        if ((config.state() & QNetworkConfiguration::Discovered) != QNetworkConfiguration::Discovered)
        {
            config = manager.defaultConfiguration();
        }

        networkSession = new QNetworkSession(config, this);
        connect(networkSession, SIGNAL(opened()), this, SLOT(sessionOpened()));

        ui->infoLabel->setText("Opening network session.");
        networkSession->open();
    }
    else
        sessionOpened();

    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->sendButton, SIGNAL(clicked()), this, SLOT(sendMessage()));
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sessionOpened()
{
    if (networkSession)
    {
        QNetworkConfiguration config = networkSession->configuration();
        QString id;
        if (config.type() == QNetworkConfiguration::UserChoice)
            id = networkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
        else
            id = config.identifier();
    }

    tcpServer = new QTcpServer(this);
    if (!tcpServer->listen(QHostAddress::LocalHost, tcpServer->serverPort()))
    {
        QMessageBox::critical(this, "Server", "Unable to start the server: " + tcpServer->errorString());
        close();

        return;
    }

    ui->infoLabel->setText(tr("The server is running on\n\nIP: %1\nport: %2\n\n").arg(tcpServer->serverAddress().toString()).arg(tcpServer->serverPort()));
}

void MainWindow::acceptConnection()
{
    clientSocket = tcpServer->nextPendingConnection();
    ui->sendButton->setEnabled(true);
    ui->messegeLineEdit->setEnabled(true);
    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(startRead()));
    connect(clientSocket, SIGNAL(disconnected()), this, SLOT(clientDisconnected()));
    connect(clientSocket, SIGNAL(disconnected()), clientSocket, SLOT(deleteLater()));
}

void MainWindow::startRead()
{
    QDataStream in(clientSocket);
    in.setVersion(QDataStream::Qt_5_1);

    if (messegeSize == 0)
    {
        if (clientSocket->bytesAvailable() < (int)sizeof(quint16))
            return;

        in >> messegeSize;
    }

    if (clientSocket->bytesAvailable() < messegeSize)
        return;

    messegeSize = 0;
    QString newMessage;
    in >> newMessage;
    ui->chatTextEdit->textCursor().insertText("client: " + newMessage + '\n');
}

void MainWindow::send()
{
    if (clientSocket)
    {
        QString temp = ui->messegeLineEdit->text();

        ui->sendButton->setEnabled(false);
        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        ui->messegeLineEdit->clear();
        out << (quint16)temp.length();
        out << temp;
        clientSocket->write(block);
        ui->chatTextEdit->textCursor().insertText("you: " + temp + '\n');
        ui->sendButton->setEnabled(true);
    }
}

void MainWindow::disconnected()
{
    ui->sendButton->setEnabled(false);
    ui->messegeLineEdit->setEnabled(false);
    QMessageBox::warning(this, "Warning!", "Client disconnected");
}
