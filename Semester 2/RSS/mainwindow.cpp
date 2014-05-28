#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass )
{
    ui->setupUi(this);

    size = 0;

    veiw = new QWebView();

    connect(veiw, SIGNAL(loadFinished(bool)), this, SLOT(parseXml()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(del()));

    ui->treeWidget->setColumnHidden(1, true);
    ui->treeWidget->setColumnHidden(2, true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fetch()
{
    ++size;
    xml.clear();

    QUrl url(ui->lineEdit->text());

    veiw->load(url);

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    manager->get(QNetworkRequest(url));
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getUrl(QNetworkReply*)));
}

void MainWindow::del()
{
    for (int i = 0; i < size; ++i)
    {
        if (ui->treeWidget->itemAt(i, 0)->text(2) == ui->lineEdit->text())
                ui->treeWidget->removeItemWidget(ui->treeWidget->itemAt(i, 0), 0);
    }
}

void MainWindow::parseXml()
{
    while (!xml.atEnd())
    {
        xml.readNext();
        if (xml.isStartElement())
        {
            if (xml.name() == "item")
            {
                if (titleString!="")
                {
                    feed = new QTreeWidgetItem;
                    feed->setText(0, titleString);
                    feed->setText(2, linkString);
                    ui->treeWidget->addTopLevelItem(feed);
                }
                linkString.clear();
                titleString.clear();
                dateString.clear();
            }
            currentTag = xml.name().toString();
        }
        else
            if (xml.isEndElement())
            {
                if (xml.name() == "item")
                {
                    QTreeWidgetItem *item = new QTreeWidgetItem(feed);
                    item->setText(0, titleString);
                    item->setText(1, dateString);
                    item->setText(2, linkString);
                    ui->treeWidget->addTopLevelItem(item);
                    titleString.clear();
                    linkString.clear();
                    dateString.clear();
                }
            }
            else
                if (xml.isCharacters() && !xml.isWhitespace())
                {
                    if (currentTag == "title")
                        titleString += xml.text().toString();
                    else if (currentTag == "link")
                        linkString += xml.text().toString();
                    else if (currentTag == "pubDate")
                        dateString += xml.text().toString();
                }
    }
}

void MainWindow::itemActivated(QTreeWidgetItem * item)
{
    ui->webView->load(QUrl(item->text(2)));
    ui->webView->show();
}

void MainWindow::getUrl(QNetworkReply *reply)
{
    switch (reply->error())
    {

    case 0:
    {
        xml.addData(reply->readAll());
        break;
    }

    default:
    {
        break;
    }

    }

    reply->deleteLater();
}
