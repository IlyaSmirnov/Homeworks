#pragma once

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtWebKit/QWebElement>
#include <QWebFrame>
#include <QWebView>
#include <QDialog>

namespace Ui {
class Bash;
}

class Bash : public QDialog
{
    Q_OBJECT

public:
    explicit Bash(QWidget *parent = 0);
    ~Bash();

public slots:
    void loadButtonWasClicked();
    void nextButtonWasClicked();
    ///find quotes after load button was clicked
    void findQuotes();
    void rulezButtonWasClicked();
    void BayanButtonWasClicked();
    void suxButtonWasClicked();

private:
    QWebView *view;
    ///quotes
    QWebElementCollection elements;
    ///ratings of quotes
    QWebElementCollection ratings;
    ///id of quotes
    QWebElementCollection id;

    Ui::Bash *ui;

    ///id of current quote
    int currentId;
    ///count of quotes which been downloaded
    int length;
};
