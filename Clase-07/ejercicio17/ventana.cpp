#include "ventana.h"

Ventana::Ventana()
    : labelMain(new QLabel("URL de la IMG"))
    , labelURL(new QLabel("https://i.kym-cdn.com/photos/images/original/000/678/956/e07.jpg"))
    , buttonSalir(new QPushButton("Salir"))
    , layout(new QGridLayout(this))
    , networkManager(new QNetworkAccessManager(this))
{
    connect(networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(descargaFinalizada(QNetworkReply*)));
    QNetworkRequest request(QUrl("https://i.kym-cdn.com/photos/images/original/000/678/956/e07.jpg"));
    networkManager->get(request);

    labelMain->setAlignment(Qt::AlignCenter);
    QFont fontMain = labelMain->font();
    fontMain.setBold(true);
    fontMain.setPointSize(12);
    labelMain->setFont(fontMain);

    labelURL->setAlignment(Qt::AlignCenter);

    layout->addWidget(labelMain, 0, 1, 1, 3);
    layout->addWidget(labelURL, 1, 1, 1, 3);
    layout->addWidget(buttonSalir, 2, 1, 1, 3);

    connect(buttonSalir, SIGNAL(clicked()), this, SLOT(cerrar()));
    this->setLayout(layout);
}

void Ventana::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    if (!imagen.isNull()) {
        this->show();
        painter.drawImage(0, 0, imagen.scaled(this->size()));
    }
}

void Ventana::descargaFinalizada(QNetworkReply* reply)
{
    imagen = QImage::fromData(reply->readAll());
    this->repaint();
}

void Ventana::cerrar()
{
    QApplication::quit();
}
