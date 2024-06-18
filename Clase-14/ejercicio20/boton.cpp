#include "boton.h"

Boton::Boton(QWidget *parent)
    : QWidget{parent}, m_color(ROJO)
{
}

void Boton::setColor(Color colorBoton)
{
    m_color = colorBoton;
    repaint();
}

void Boton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    QColor colorToUse;
    switch (m_color)
    {
    case ROJO:
        colorToUse = Qt::red;
        break;
    case AZUL:
        colorToUse = Qt::blue;
        break;
    case MAGENTA:
        colorToUse = Qt::magenta;
        break;
    case VERDE:
        colorToUse = Qt::darkGreen;
        break;
    }

    // Ajustar la transparencia al 50%
    colorToUse.setAlpha(128); // 128 es aproximadamente el 50% de transparencia

    painter.fillRect(rect(), colorToUse);
}

void Boton::mousePressEvent(QMouseEvent *)
{
    emit signal_click();
}
