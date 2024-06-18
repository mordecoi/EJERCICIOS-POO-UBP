#include "login.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
    , nombreLabel(new QLabel("Usuario:"))
    , claveLabel(new QLabel("Clave:"))
    , legajoLineEdit(new QLineEdit)
    , usuarioLineEdit(new QLineEdit)
    , apellidoLineEdit(new QLineEdit)
    , claveLineEdit(new QLineEdit)
    , weatherButton(new QPushButton("Mostrar Clima"))
    , labelTemperatura(new QLabel("N/A"))
    , labelClima(new QLabel("Temperatura:"))
{
    claveLineEdit->setEchoMode(QLineEdit::Password);

    loginButton = new QPushButton("Login");

    layout = new QGridLayout(this);
    layout->addWidget(nombreLabel, 0, 0);
    layout->addWidget(usuarioLineEdit, 0, 1);
    layout->addWidget(claveLabel, 2, 0);
    layout->addWidget(claveLineEdit, 2, 1);
    layout->addWidget(loginButton, 4, 0, 1, 2);
    layout->addWidget(labelClima, 3, 0);
    layout->addWidget(labelTemperatura, 3, 1);
    layout->addWidget(weatherButton, 5, 0, 1, 2);

    setLayout(layout);

    connect(loginButton, SIGNAL(clicked()), this, SLOT(attemptLogin()));
    connect(claveLineEdit, SIGNAL(returnPressed()), this, SLOT(attemptLogin()));
    connect(usuarioLineEdit, SIGNAL(returnPressed()), this, SLOT(attemptLogin()));
    connect(weatherButton, SIGNAL(clicked()), this, SLOT(mostrarClima()));
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

void Login::mostrarClima() {
    labelTemperatura->setVisible(!labelTemperatura->isVisible());
    if (labelTemperatura->isVisible()) {
        emit climaRequested("Cordoba"); // Cambia "Cordoba" por la ciudad de tu elección
    }
}

void Login::setBackgroundImage(const QString &imageUrl)
{
    QPixmap background(imageUrl);
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(background));
    this->setPalette(palette);
    this->setAutoFillBackground(true);
}

void Login::actualizarTemperatura(const QString &temperatura) {
    labelTemperatura->setText(temperatura);
}
