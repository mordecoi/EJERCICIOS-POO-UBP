#ifndef LOGIN_H
#define LOGIN_H

#include <QGridLayout>
#include <QMessageBox>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

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
    QGridLayout *layout;
    QString backgroundImage;
};

#endif // LOGIN_H
