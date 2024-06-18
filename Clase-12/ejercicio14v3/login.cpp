#include "login.h"
#include <QMessageBox>

Login::Login(QWidget *parent)
    : QWidget(parent)
    , labelUsuario(new QLabel("Usuario:"))
    , labelClave(new QLabel("Clave:"))
    , lineEditUsuario(new QLineEdit)
    , lineEditClave(new QLineEdit)
    , buttonLogin(new QPushButton("Login"))
    , layout(new QGridLayout(this))
{
    lineEditClave->setEchoMode(QLineEdit::Password);

    layout->addWidget(labelUsuario, 0, 0);
    layout->addWidget(lineEditUsuario, 0, 1);
    layout->addWidget(labelClave, 1, 0);
    layout->addWidget(lineEditClave, 1, 1);
    layout->addWidget(buttonLogin, 2, 0, 1, 2);

    setLayout(layout);

    connect(buttonLogin, &QPushButton::clicked, this, &Login::attemptLogin);
    connect(lineEditClave, &QLineEdit::returnPressed, this, &Login::attemptLogin);
    connect(lineEditUsuario, &QLineEdit::returnPressed, this, &Login::attemptLogin);
}

void Login::attemptLogin()
{
    QString usuario = lineEditUsuario->text();
    QString clave = lineEditClave->text();
    if (usuario == "admin" && clave == "1234") {
        emit loginSuccessful();
        QString prueba = "SELECT * FROM usuarios";
        db.ejecutarConsulta(prueba);

    } else {
        QMessageBox::warning(this, "Login Fallido", "Usuario o clave incorrectos.");
        lineEditClave->clear();
    }
}
