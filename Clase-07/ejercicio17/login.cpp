#include "login.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
    , labelUsuario(new QLabel("Usuario:"))
    , labelClave(new QLabel("Clave:"))
    , labelBienvenido(new QLabel("Bienvenido"))
    , lineEditUsuario(new QLineEdit)
    , lineEditClave(new QLineEdit)
    , buttonLogin(new QPushButton("Login"))
{
    lineEditClave->setEchoMode(QLineEdit::Password);

    QFont fontBienvenido = labelBienvenido->font();
    fontBienvenido.setBold(true);
    fontBienvenido.setPointSize(12);
    labelBienvenido->setFont(fontBienvenido);
    labelBienvenido->setAlignment(Qt::AlignCenter);

    layout = new QGridLayout(this);
    layout->addWidget(labelUsuario, 0, 0);
    layout->addWidget(lineEditUsuario, 0, 1);
    layout->addWidget(labelClave, 1, 0);
    layout->addWidget(lineEditClave, 1, 1);
    layout->addWidget(buttonLogin, 2, 0, 1, 2);
    layout->addWidget(labelBienvenido, 3, 0, 1, 2);

    setLayout(layout);

    connect(buttonLogin, SIGNAL(clicked()), this, SLOT(validarUsuario()));
    connect(lineEditClave, SIGNAL(returnPressed()), this, SLOT(validarUsuario()));
    connect(lineEditUsuario, SIGNAL(returnPressed()), this, SLOT(validarUsuario()));

    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(descargaFinalizada(QNetworkReply*)));

    QNetworkRequest request(QUrl("https://i.kym-cdn.com/photos/images/original/002/799/572/484.jpg"));
    networkManager->get(request);
}

void Login::attemptLogin()
{
    QString usuario = lineEditUsuario->text();
    QString clave = lineEditClave->text();
    if (usuario == "admin" && clave == "1111") {
        emit loginSuccessful();
        close();
    } else {
        lineEditClave->clear();
        emit loginFailed();
    }
}

void Login::validarUsuario()
{
    if (lineEditUsuario->text() == "admin" && lineEditClave->text() == "1234") {
        Ventana* ventana_point = new Ventana; // Suponiendo que la clase Ventana está definida
        this->hide();
        ventana_point->showMaximized();
    } else {
        lineEditClave->clear();
    }
}

void Login::descargaFinalizada(QNetworkReply* reply)
{
    imagen = QImage::fromData(reply->readAll());
    this->repaint();
}

void Login::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    if (!imagen.isNull()) {
        painter.drawImage(0, 0, imagen.scaled(this->size()));
        QLabel* labelURL = new QLabel("URL IMG: https://i.kym-cdn.com/photos/images/original/002/799/572/484.jpg");
        labelURL->setAlignment(Qt::AlignCenter);
        layout->addWidget(labelURL, 4, 0, 1, 2);
    }
}
