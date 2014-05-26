#include "bash.h"
#include "ui_bash.h"

Bash::Bash(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Bash)
{
    ui->setupUi(this);

    ui->quoteTextEdit->setText("Press Load");
    ui->ratingLineEdit->setEnabled(false);

    setWindowTitle("Bash");
    ui->nextButton->setEnabled(false);
    ui->rulezButton->setEnabled(false);
    ui->bayanButton->setEnabled(false);
    ui->suxButton->setEnabled(false);

    connect(ui->loadButton, SIGNAL(clicked()), this, SLOT(loadButtonWasClicked()));
    connect(ui->nextButton, SIGNAL(clicked()), this, SLOT(nextButtonWasClicked()));
    connect(ui->rulezButton, SIGNAL(clicked()), this, SLOT(rulezButtonWasClicked()));
    connect(ui->bayanButton, SIGNAL(clicked()), this, SLOT(BayanButtonWasClicked()));
    connect(ui->suxButton, SIGNAL(clicked()), this, SLOT(suxButtonWasClicked()));
}

Bash::~Bash()
{
    delete ui;
}

void Bash::loadButtonWasClicked()
{
    ui->quoteTextEdit->setText("Loading...");
    view = new QWebView();
    view->load(QUrl("http://bash.im/"));
    connect(view, SIGNAL(loadFinished(bool)), this, SLOT(findQuotes()));

    ui->loadButton->setEnabled(false);
}

void Bash::nextButtonWasClicked()
{
    if (currentId == length)
        currentId = 0;

    ui->quoteTextEdit->setText(elements.at(currentId).toPlainText() + "\n\n");
    ui->ratingLineEdit->setText(ratings.at(currentId).toPlainText());
    ++currentId;

    ui->rulezButton->setEnabled(true);
    ui->bayanButton->setEnabled(true);
    ui->suxButton->setEnabled(true);
}

void Bash::findQuotes()
{
    ui->quoteTextEdit->setText("Completed. Press Next to read quotes from bash.im");
    ui->nextButton->setEnabled(true);
    elements = view->page()->mainFrame()->findAllElements("div[class=text]");
    ratings = view->page()->mainFrame()->findAllElements("span[class=rating]");
    id = view->page()->mainFrame()->findAllElements("a[class=id]");
    currentId = 0;
    length = elements.toList().length();
}

void Bash::rulezButtonWasClicked()
{
    QString qStr = "http://bash.im/quote/" + id.at(currentId).toPlainText().mid(1);
    QUrl url(qStr);
    QNetworkRequest networkRequest(url);
    networkRequest.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    QNetworkAccessManager *nam = new QNetworkAccessManager(this);
    nam->post(networkRequest, "/rulez");
}

void Bash::BayanButtonWasClicked()
{
    QString qStr = "http://bash.im/quote/" + id.at(currentId).toPlainText().mid(1);
    QUrl url(qStr);
    QNetworkRequest networkRequest(url);
    networkRequest.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    QNetworkAccessManager *nam = new QNetworkAccessManager(this);
    nam->post(networkRequest, "/bayan");
}

void Bash::suxButtonWasClicked()
{
    QString qStr = "http://bash.im/quote/" + id.at(currentId).toPlainText().mid(1);
    QUrl url(qStr);
    QNetworkRequest networkRequest(url);
    networkRequest.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    QNetworkAccessManager *nam = new QNetworkAccessManager(this);
    nam->post(networkRequest, "/sux");
}
