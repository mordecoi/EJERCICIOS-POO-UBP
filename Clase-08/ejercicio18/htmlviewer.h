#ifndef HTMLVIEWER_H
#define HTMLVIEWER_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class HtmlViewer : public QWidget
{
    Q_OBJECT

public:
    HtmlViewer(QWidget *parent = nullptr);

private slots:
    void fetchHtml();
    void displayHtml(QNetworkReply* reply);

private:
    QLabel *labelUrl;
    QLineEdit *lineEditUrl;
    QTextEdit *textEditHtml;
    QGridLayout *layout;
    QNetworkAccessManager *networkManager;
};

#endif // HTMLVIEWER_H
