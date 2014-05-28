#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTreeWidget>
#include <QXmlStreamReader>
#include <QtNetwork>
#include <QDebug>
#include <QList>
#include <QWebView>
#include <QWebFrame>

namespace Ui
{
class MainWindowClass;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void fetch();
    void del();
    void itemActivated(QTreeWidgetItem *item);
    void parseXml();
    void getUrl(QNetworkReply *reply);

private:
    Ui::MainWindowClass *ui;

    QWebView *veiw;

    QString currentTag;
    QString linkString;
    QString titleString;
    QString dateString;

    QTreeWidgetItem *feed;
    QXmlStreamReader xml;
    int size;
};
