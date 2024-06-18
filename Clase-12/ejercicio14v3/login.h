#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "admin_db.h"

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

    admin_db db;
};

#endif // LOGIN_H
