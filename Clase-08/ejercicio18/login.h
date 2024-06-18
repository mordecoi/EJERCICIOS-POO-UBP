#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QGridLayout>
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

private slots:
    void attemptLogin();

private:
    QLabel *labelUsuario;
    QLabel *labelClave;
    QLineEdit *lineEditUsuario;
    QLineEdit *lineEditClave;
    QPushButton *buttonLogin;
    QGridLayout *layout;
};

#endif // LOGIN_H
