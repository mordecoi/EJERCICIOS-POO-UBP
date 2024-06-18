#include "htmlviewer.h"

HtmlViewer::HtmlViewer(QWidget *parent)
    : QWidget(parent)
    , labelUrl(new QLabel("URL:"))
    , lineEditUrl(new QLineEdit)
    , textEditHtml(new QTextEdit)
    , layout(new QGridLayout(this))
    , networkManager(new QNetworkAccessManager(this))
{
    layout->addWidget(labelUrl, 0, 0);
    layout->addWidget(lineEditUrl, 0, 1);
    layout->addWidget(textEditHtml, 1, 0, 1, 2);

    setLayout(layout);

    connect(lineEditUrl, &QLineEdit::returnPressed, this, &HtmlViewer::fetchHtml);
    connect(networkManager, &QNetworkAccessManager::finished, this, &HtmlViewer::displayHtml);
}

void HtmlViewer::fetchHtml()
{
    QString url = lineEditUrl->text();
    networkManager->get(QNetworkRequest(QUrl(url)));
}

void HtmlViewer::displayHtml(QNetworkReply* reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        textEditHtml->setPlainText(responseData);
    } else {
        textEditHtml->setPlainText("Error al obtener la URL.");
    }
    reply->deleteLater();
}
