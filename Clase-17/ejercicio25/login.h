#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QFont>
#include <QMessageBox>

#include "label.h"
#include "ventana.h"
#include "admindb.h"
#include "admin.h"

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private:
    QGridLayout* layout;
    QLabel* lblUsuario, *lblPassword;
    QLineEdit* leUsuario, *lePassword;
    QPushButton* btnIngresar, *btnRegistrar;
    Ventana* ventana;
    AdminDB* admindb;
    Admin* admin;

private slots:
    void slotRegistrar();
    void slotIngresar();
    void slotMostrarTree();

signals:
    void signalGoToTree();
};

#endif // LOGIN_H
