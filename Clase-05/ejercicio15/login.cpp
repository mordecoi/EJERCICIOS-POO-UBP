#include "login.h"
#include "formulario.h"

Login::Login()
    : LUsuario(new QLabel("Usuario")),
    LClave(new QLabel("Clave")),
    LeUsuario(new QLineEdit),
    LeClave(new QLineEdit),
    PBEntrar(new QPushButton("Entrar")),
    Layout(new QGridLayout)
{
    LeClave->setEchoMode(QLineEdit::PasswordEchoOnEdit);

    Layout->addWidget(LUsuario, 0, 0, Qt::AlignCenter);
    Layout->addWidget(LClave, 1, 0, Qt::AlignCenter);
    Layout->addWidget(LeUsuario, 0, 1, Qt::AlignCenter);
    Layout->addWidget(LeClave, 1, 1, Qt::AlignCenter);
    Layout->addWidget(PBEntrar, 2, 0, 1, 2, Qt::AlignCenter);

    connect(PBEntrar, SIGNAL(clicked()), this, SLOT(SlotValidarUsuario()));
    connect(LeClave, SIGNAL(returnPressed()), this, SLOT(SlotValidarUsuario()));
    connect(&formulario, SIGNAL(signalCerrarLogin()), this, SLOT(close()));

    this->setLayout(Layout);
}

void Login::SlotValidarUsuario()
{
    if (LeUsuario->text() == "admin" && LeClave->text() == "1111") {
        formulario.show();
    } else {
        LeClave->clear();
    }
}
