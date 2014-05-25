#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    networkSession(0),
    messegeSize(0)
{
    ui->setupUi(this);

    setWindowTitle("Client");

    ui->hostComboBox->setEditable(true);
    ui->exitButton->setAutoDefault(false);
    ui->sendButton->setEnabled(false);
    ui->chatTextEdit->setReadOnly(true);
    ui->messegeLineEdit->setEnabled(false);
    ui->portLineEdit->setValidator(new QIntValidator(1, 65535, this));

    QString name = QHostInfo::localHostName();
    if (!name.isEmpty())
    {
        ui->hostComboBox->addItem(name);
        QString domain = QHostInfo::localDomainName();
        if (!domain.isEmpty())
            ui->hostComboBox->addItem(name + QChar('.') + domain);
    }
    if (name != "localhost")
        ui->hostComboBox->addItem("localhost");

    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    for (int i = 0; i < ipAddressesList.size(); ++i)
        if (!ipAddressesList.at(i).isLoopback())
            ui->hostComboBox->addItem(ipAddressesList.at(i).toString());

    serverSocket = new QTcpSocket(this);

    connect(serverSocket, SIGNAL(readyRead()), this, SLOT(startRead()));
    connect(serverSocket, SIGNAL(connected()), this, SLOT(disableAddressChange()));
    connect(serverSocket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(serverSocket, SIGNAL(disconnected()), this, SLOT(enableAddressChange()));
    connect(serverSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));

    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->sendButton, SIGNAL(clicked()), this, SLOT(send()));
    connect(ui->connectButton, SIGNAL(clicked()), this, SLOT(tryConnect()));

    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired)
    {
        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
        settings.endGroup();

        QNetworkConfiguration config = manager.configurationFromIdentifier(id);
        if ((config.state() & QNetworkConfiguration::Discovered) !=
                QNetworkConfiguration::Discovered)
            config = manager.defaultConfiguration();

        networkSession = new QNetworkSession(config, this);
        connect(networkSession, SIGNAL(opened()), this, SLOT(sessionOpened()));

        networkSession->open();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::tryConnect()
{
    if (ui->connectButton->text() == "Disconnect")
    {
        ui->connectButton->setText("Connect");
        serverSocket->close();
        ui->chatTextEdit->setText("");
        ui->messegeLineEdit->setEnabled(false);
        return;
    }

    disableAddressChange();
    serverSocket->connectToHost(ui->hostComboBox->currentText(), ui->portLineEdit->text().toInt());

    if (serverSocket->waitForConnected(3000))
    {
        ui->sendButton->setEnabled((!networkSession || networkSession->isOpen()) && (!ui->hostComboBox->currentText().isEmpty()) && (!ui->portLineEdit->text().isEmpty()));
        ui->messegeLineEdit->setEnabled(true);
        ui->connectButton->setText("Disconnect");
    }
    else
    {
        QMessageBox::information(this, "Client", "Connection timed out");
        enableAddressChange();
        ui->messegeLineEdit->setEnabled(false);
    }
}

void MainWindow::displayError(QAbstractSocket::SocketError socketError)
{
    serverSocket->close();
    switch (socketError)
    {

    case QAbstractSocket::RemoteHostClosedError:
    {
        break;
    }

    case QAbstractSocket::HostNotFoundError:
    {
        QMessageBox::information(this, "Client", "The host was not found. Please check the host name and port settings.");
        break;
    }

    case QAbstractSocket::ConnectionRefusedError:
    {
        QMessageBox::information(this, "Client", "The connection was refused by the peer.  Make sure the fortune server is running,  and check that the host name and port settings are correct.");
        break;
    }

    default:
    {
        QMessageBox::information(this, "Client", "The following error occurred: " + (serverSocket->errorString()));
    }

    }

    enableAddressChange();
}

void MainWindow::sessionOpened()
{
    QNetworkConfiguration config = networkSession->configuration();
    QString id;
    if (config.type() == QNetworkConfiguration::UserChoice)
        id = networkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
    else
        id = config.identifier();

    ui->sendButton->setEnabled((!networkSession || networkSession->isOpen()) && (!ui->hostComboBox->currentText().isEmpty()) && (!ui->portLineEdit->text().isEmpty()));
}

void MainWindow::startRead()
{
    QDataStream in(serverSocket);
    in.setVersion(QDataStream::Qt_5_1);

    if (messegeSize == 0)
    {
        if (serverSocket->bytesAvailable() < (int)sizeof(quint16))
            return;

        in >> messegeSize;
    }

    if (serverSocket->bytesAvailable() < messegeSize)
        return;

    messegeSize = 0;
    QString newMessage;
    in >> newMessage;
    ui->chatTextEdit->textCursor().insertText("Server: " + newMessage + '\n');
}

void MainWindow::send()
{
    ui->sendButton->setEnabled(false);

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    QString temp = ui->messegeLineEdit->text();
    ui->messegeLineEdit->clear();
    out << (quint16)temp.length();
    out << temp;
    serverSocket->write(block);

    ui->chatTextEdit->textCursor().insertText("You: " + temp + '\n');
    ui->sendButton->setEnabled(true);
}

void MainWindow::disconnected()
{
    ui->sendButton->setEnabled(false);
    enableAddressChange();
    QMessageBox::warning(this, "Warning!", "Disconnected");
}

void MainWindow::enableAddressChange()
{
    ui->hostComboBox->setEnabled(true);
    ui->portLineEdit->setEnabled(true);
}

void MainWindow::disableAddressChange()
{
    ui->hostComboBox->setEnabled(false);
    ui->portLineEdit->setEnabled(false);
}
