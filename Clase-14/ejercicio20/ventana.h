#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QImage>
#include <QPainter>
#include "boton.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Ventana;
}
QT_END_NAMESPACE

class Ventana : public QWidget
{
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = nullptr);
    ~Ventana();

private:
    Ui::Ventana *ui;
    QNetworkAccessManager *m_networkManager;
    QImage m_image;

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void slot_descargaFinalizada(QNetworkReply* reply);
    void configureWidget(Boton *widget, const QString &text, const QFont &font);
};

#endif // VENTANA_H
