#include <QApplication>
#include "login.h"
#include "ventana.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Login login;
    Ventana ventana;

    QObject::connect(&login, &Login::signal_login_successful, [&]() {
        login.hide();
        ventana.show();
    });

    QObject::connect(&ventana, &Ventana::signal_volver_login, [&]() {
        ventana.hide();
        login.show();
    });

    login.show();
    return a.exec();
}
