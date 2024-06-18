#include "login.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
{
    layout = new QGridLayout();

    lblUsuario = new QLabel("Usuario:");
    lblPassword = new QLabel("Password:");
    btnIngresar = new QPushButton("Ingresar");
    btnRegistrar = new QPushButton("Registrar");

    QFont font;
    font.setCapitalization(QFont::AllUppercase);
    font.setPixelSize(12);

    lblUsuario->setFont(font);
    lblPassword->setFont(font);
    btnIngresar->setFont(font);
    btnRegistrar->setFont(font);

    leUsuario = new QLineEdit();
    lePassword = new QLineEdit();
    lePassword->setEchoMode(QLineEdit::Password);

    leUsuario->setPlaceholderText("Ingresar Usuario");
    lePassword->setPlaceholderText("Ingresar Password");

    layout->addWidget(lblUsuario, 0, 0, 1, 1);
    layout->addWidget(leUsuario, 0, 1, 1, 1);
    layout->addWidget(lblPassword, 1, 0, 1, 1);
    layout->addWidget(lePassword, 1, 1, 1, 1);
    layout->addWidget(btnIngresar, 2, 1, 1, 1);
    layout->addWidget(btnRegistrar, 3, 1, 1, 1);

    setLayout(layout);

    connect(btnIngresar, SIGNAL(clicked()), this, SLOT(slotIngresar()));
    connect(btnRegistrar, SIGNAL(clicked()), this, SLOT(slotRegistrar()));
    connect(this, SIGNAL(signalGoToTree()), this, SLOT(slotMostrarTree()));
}

Login::~Login() {}

void Login::slotIngresar() {
    admindb = new AdminDB(this);
    if (admindb->connectDatabase("D:/Usuarios/Maxi/Desktop/POO/subidagithub/ejercicio25/usuariosv2.sqlite")) {
        if (admindb->validateUser("usuarios", leUsuario->text(), lePassword->text())) {
            qDebug() << "Exito Ingresando con el Usuario!";
            QMessageBox::information(this, "Ingreso Éxito", "¡Ingreso de usuario correctamente!");
            emit signalGoToTree();
        } else {
            qDebug() << "Algo ha ido mal en el Ingreso.";
            QMessageBox::information(this, "Error al ingresar", "Ocurrió un error al intentar ingresar.");
            lePassword->clear();
        }
    } else {
        qDebug() << "No se pudo conectar a la DB";
    }
}

void Login::slotRegistrar() {
    ventana = new Ventana();
    close();
    ventana->show();
}

void Login::slotMostrarTree() {
    admin = new Admin();
    hide();
}
