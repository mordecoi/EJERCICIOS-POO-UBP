#include "login.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
    , nombreLabel(new QLabel("Usuario:"))
    , claveLabel(new QLabel("Clave:"))
    , legajoLineEdit(new QLineEdit)
    , usuarioLineEdit(new QLineEdit)
    , apellidoLineEdit(new QLineEdit)
    , claveLineEdit(new QLineEdit)
{
    claveLineEdit->setEchoMode(QLineEdit::Password);

    loginButton = new QPushButton("Login");


    layout = new QGridLayout(this);
    layout->addWidget(nombreLabel, 0, 0);
    layout->addWidget(usuarioLineEdit, 0, 1);
    layout->addWidget(claveLabel, 2, 0);
    layout->addWidget(claveLineEdit, 2, 1);
    layout->addWidget(loginButton, 4, 0, 1, 2);

    setLayout(layout);

    connect(loginButton, SIGNAL(clicked()), this, SLOT(attemptLogin()));
    connect(claveLineEdit, SIGNAL(returnPressed()), this, SLOT(attemptLogin()));
    connect(usuarioLineEdit, SIGNAL(returnPressed()), this, SLOT(attemptLogin()));
}

void Login::attemptLogin()
{
    QString usuario = usuarioLineEdit->text();
    QString clave = claveLineEdit->text();
    if (usuario == "admin" && clave == "1111") {
        emit loginSuccessful();
        close();
    } else {
        claveLineEdit->clear();
        emit loginFailed();
    }
}
