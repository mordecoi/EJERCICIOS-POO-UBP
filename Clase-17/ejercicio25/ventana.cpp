#include "ventana.h"

Ventana::Ventana(QWidget *parent)
    : QWidget(parent)
{
    layout = new QGridLayout();

    lblUsuario = new QLabel("Usuario:");
    lblPassword = new QLabel("Password:");
    lblNombre = new QLabel("Nombre:");
    lblApellido = new QLabel("Apellido:");
    btnRegistrar = new QPushButton("Registrarse");

    QFont font;
    font.setBold(true);
    font.setCapitalization(QFont::AllUppercase);
    font.setPixelSize(12);

    lblUsuario->setFont(font);
    lblPassword->setFont(font);
    lblNombre->setFont(font);
    lblApellido->setFont(font);
    btnRegistrar->setFont(font);

    leUsuario = new QLineEdit();
    leUsuario->setPlaceholderText("Ingrese su Nuevo Usuario");
    lePassword = new QLineEdit();
    lePassword->setPlaceholderText("Ingrese su Nueva Password");
    lePassword->setEchoMode(QLineEdit::Password);
    leNombre = new QLineEdit();
    leNombre->setPlaceholderText("Ingrese su Nombre");
    leApellido = new QLineEdit();
    leApellido->setPlaceholderText("Ingrese su Apellido");

    layout->addWidget(lblUsuario, 0, 0, 1, 1);
    layout->addWidget(leUsuario, 0, 1, 1, 1);
    layout->addWidget(lblPassword, 1, 0, 1, 1);
    layout->addWidget(lePassword, 1, 1, 1, 1);
    layout->addWidget(lblNombre, 2, 0, 1, 1);
    layout->addWidget(leNombre, 2, 1, 1, 1);
    layout->addWidget(lblApellido, 3, 0, 1, 1);
    layout->addWidget(leApellido, 3, 1, 1, 1);
    layout->addWidget(btnRegistrar, 4, 0, 1, 2);

    setLayout(layout);

    connect(btnRegistrar, SIGNAL(clicked()), this, SLOT(slotRegistrar()));
}

void Ventana::slotRegistrar() {
    admindb = new AdminDB(this);
    if (admindb->connectDatabase("D:/Usuarios/Maxi/Desktop/POO/subidagithub/ejercicio25/usuariosv2.sqlite")) {
        if (!leUsuario->text().isEmpty() && !lePassword->text().isEmpty() &&
            !leNombre->text().isEmpty() && !leApellido->text().isEmpty()) {
            if (admindb->userExists("usuarios", leUsuario->text())) {
                qDebug() << "Ya existe el Usuario. Intente con otro Usuario";
                QMessageBox::warning(this, "Ingreso Repetido", "¡El usuario ingresado YA existe!");
                leUsuario->setText("");
                lePassword->setText("");
            } else {
                qDebug() << "Éxito en el Registro!";
                QMessageBox::information(this, "Ingreso Éxito", "¡Ingreso de usuario correctamente!");
                admindb->insertUser("usuarios", leUsuario->text(), lePassword->text(),
                                         leNombre->text(), leApellido->text());
                close();
            }
        } else {
            qDebug() << "Alguno de los Datos requeridos está Vacío";
            QMessageBox::warning(this, "Datos incompletos", "Complete TODOS los campos");
        }
    } else {
        qDebug() << "No se pudo conectar a la DB";
        QMessageBox::warning(this, "Error DB", "No se pudo conectar a la DB!");
    }
}
