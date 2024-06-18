#include "formulario.h"

Formulario::Formulario()
    : labelLegajo(new QLabel("Legajo:")),
    labelNombre(new QLabel("Nombre:")),
    labelApellido(new QLabel("Apellido:")),
    labelNomCaptcha(new QLabel("Captcha:")),
    labelCaptcha(new QLabel("")),
    lineEditLegajo(new QLineEdit),
    lineEditNombre(new QLineEdit),
    lineEditApellido(new QLineEdit),
    lineEditCaptcha(new QLineEdit),
    pushButtonAlta(new QPushButton("Alta")),
    layout(new QGridLayout),
    numCaptcha(0)
{
    layout->addWidget(labelLegajo, 0, 0, Qt::AlignCenter);
    layout->addWidget(labelNombre, 1, 0, Qt::AlignCenter);
    layout->addWidget(labelApellido, 2, 0, Qt::AlignCenter);

    layout->addWidget(lineEditLegajo, 0, 1, Qt::AlignCenter);
    layout->addWidget(lineEditNombre, 1, 1, Qt::AlignCenter);
    layout->addWidget(lineEditApellido, 2, 1, Qt::AlignCenter);

    layout->addWidget(labelNomCaptcha, 3, 0, Qt::AlignCenter);
    layout->addWidget(labelCaptcha, 4, 0, Qt::AlignCenter);
    layout->addWidget(lineEditCaptcha, 5, 0, Qt::AlignCenter);
    layout->addWidget(pushButtonAlta, 3, 1, 3, 1, Qt::AlignCenter);

    connect(pushButtonAlta, SIGNAL(clicked()), this, SLOT(validarCaptcha()));
    connect(lineEditCaptcha, SIGNAL(returnPressed()), this, SLOT(validarCaptcha()));

    this->setLayout(layout);

    generarCaptcha();
}

void Formulario::validarCaptcha()
{
    if (lineEditCaptcha->text() == QString::number(numCaptcha))
    {
        lineEditLegajo->clear();
        lineEditNombre->clear();
        lineEditApellido->clear();
        lineEditCaptcha->clear();
        generarCaptcha();

        this->hide();
        emit signalCerrarLogin();
    }
    else
    {
        generarCaptcha();
        lineEditCaptcha->clear();
    }
}

void Formulario::generarCaptcha()
{
    std::srand(static_cast<unsigned int>(time(nullptr)));
    numCaptcha = std::rand() % 1000 + 1;
    labelCaptcha->setText(QString::number(numCaptcha));
}

void Formulario::cerrarLogin()
{
    emit signalCerrarLogin();
}
