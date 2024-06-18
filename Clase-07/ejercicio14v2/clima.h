#ifndef CLIMA_H
#define CLIMA_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>

class Clima : public QObject {
    Q_OBJECT
public:
    explicit Clima(QObject *parent = nullptr);

    void obtenerTemperatura(const QString &ciudad);

signals:
    void climaObtenido(const QString &temperatura);

private:
    QNetworkAccessManager *manager;

private slots:
    void respuestaRecibida(QNetworkReply *reply);
};

#endif // CLIMA_H
