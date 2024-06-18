#ifndef LOGIN_H
#define LOGIN_H

#include <QGridLayout>
#include <QMessageBox>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QImage>
#include <QPainter>
#include <QApplication>
#include "ventana.h"

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);

signals:
    void loginSuccessful();
    void loginFailed();

private slots:
    void attemptLogin();
    void validarUsuario();
    void descargaFinalizada(QNetworkReply* reply);

protected:
    void paintEvent(QPaintEvent* ) override;

private:
    QLabel *labelUsuario;
    QLabel *labelClave;
    QLabel *labelBienvenido;
    QLineEdit *lineEditUsuario;
    QLineEdit *lineEditClave;
    QPushButton *buttonLogin;
    QGridLayout *layout;

    QNetworkAccessManager* networkManager;
    QImage imagen;
};

#endif // LOGIN_H
