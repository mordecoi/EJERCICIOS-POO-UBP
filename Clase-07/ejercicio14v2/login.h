#ifndef LOGIN_H
#define LOGIN_H

#include <QGridLayout>
#include <QMessageBox>
#include <QWidget>
#include <QPixmap>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "clima.h"

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);

signals:
    void loginSuccessful();
    void loginFailed();
    void climaRequested(const QString &ciudad); // Nueva señal para solicitar el clima

private slots:
    void attemptLogin();
    void mostrarClima();
    void actualizarTemperatura(const QString &temperatura);

public slots:
    void setBackgroundImage(const QString &imageUrl); // Nuevo método para establecer la imagen de fondo

private:
    QLabel *legajoLabel;
    QLabel *nombreLabel;
    QLabel *apellidoLabel;
    QLabel *claveLabel;
    QLineEdit *legajoLineEdit;
    QLineEdit *usuarioLineEdit;
    QLineEdit *apellidoLineEdit;
    QLineEdit *claveLineEdit;
    QPushButton *loginButton;
    QPushButton *weatherButton; // Nuevo botón para solicitar el clima
    QGridLayout *layout;
    QLabel *labelTemperatura;
    QLabel *labelClima;
    QString backgroundImage;
    Clima weather;
};

#endif // LOGIN_H
