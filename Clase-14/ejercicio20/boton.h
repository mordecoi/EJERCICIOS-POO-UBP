#ifndef BOTON_H
#define BOTON_H

#include <QWidget>
#include <QPainter>

class Boton : public QWidget
{
    Q_OBJECT
public:
    explicit Boton(QWidget *parent = nullptr);

    enum Color { ROJO, AZUL, MAGENTA, VERDE };

    void setColor(Color colorBoton);

private:
    Color m_color;

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

signals:
    void signal_click();
};

#endif // BOTON_H
