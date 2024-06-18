#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include "formulario.h"

class Login : public QWidget
{
    Q_OBJECT
private:
    QLabel *LUsuario, *LClave;
    QLineEdit *LeUsuario, *LeClave;
    QPushButton *PBEntrar, *PBEsconderClima;
    QGridLayout *Layout;
    Formulario formulario;

public:
    Login();
private slots:
    void SlotValidarUsuario();
};

#endif // LOGIN_H
