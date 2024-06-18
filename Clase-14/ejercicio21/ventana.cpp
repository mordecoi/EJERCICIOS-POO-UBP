#include "ventana.h"
#include "ui_ventana.h"

Ventana::Ventana(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ventana)
{
    ui->setupUi(this);
    connect(ui->btnVolver, &QPushButton::clicked, this, &Ventana::on_btnVolver_clicked);
}

Ventana::~Ventana()
{
    delete ui;
}

void Ventana::on_btnVolver_clicked()
{
    emit signal_volver_login();
    this->hide();
}
