#include "ventana.h"
#include "ui_ventana.h"

#include <QGridLayout>
#include <QLabel>
#include <QFont>

Ventana::Ventana(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Ventana)
    , m_networkManager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);

    connect(m_networkManager, &QNetworkAccessManager::finished, this, &Ventana::slot_descargaFinalizada);
    QNetworkRequest request(QUrl("https://cdn.ipadizate.com/2020/05/LG-Q7-Stock-Wallpaper-1080x2160-02.jpg"));
    m_networkManager->get(request);

    ui->WidgetOne->setColor(Boton::ROJO);
    ui->WidgetTwo->setColor(Boton::AZUL);
    ui->WidgetThree->setColor(Boton::MAGENTA);
    ui->WidgetFour->setColor(Boton::AZUL);
    ui->WidgetFive->setColor(Boton::VERDE);

    QFont font;
    font.setBold(true);
    font.setPointSize(12);

    configureWidget(ui->WidgetOne, "Mi Dentista", font);
    configureWidget(ui->WidgetTwo, "Visitas", font);
    configureWidget(ui->WidgetThree, "Técnicas de Higiene", font);
    configureWidget(ui->WidgetFour, "Mi Boca", font);
    configureWidget(ui->WidgetFive, "Hora de Cepillarse", font);
}

Ventana::~Ventana()
{
    delete ui;
}

void Ventana::configureWidget(Boton *widget, const QString &text, const QFont &font)
{
    QGridLayout *layout = new QGridLayout;
    QLabel *label = new QLabel;
    label->setText(text);
    label->setFont(font);
    layout->addWidget(label, 0, 0, 1, 1, Qt::AlignLeft);
    widget->setLayout(layout);
    connect(widget, &Boton::signal_click, this, &Ventana::close);
}

void Ventana::slot_descargaFinalizada(QNetworkReply* reply) {
    m_image = QImage::fromData(reply->readAll());
    repaint();
    show();
}

void Ventana::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    if (!m_image.isNull()) {
        painter.drawImage(0, 0, m_image.scaled(size()));
    }
}
