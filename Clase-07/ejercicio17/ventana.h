#ifndef VENTANA_H
#define VENTANA_H

#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QImage>
#include <QPainter>

class Ventana : public QWidget {
    Q_OBJECT
private:
    QLabel* labelMain;
    QLabel* labelURL;
    QPushButton* buttonSalir;
    QGridLayout* layout;

    QNetworkAccessManager* networkManager;
    QImage imagen;

public:
    Ventana();

private slots:
    void descargaFinalizada(QNetworkReply* reply);
    void cerrar();

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // VENTANA_H
