#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>

namespace Ui {
class Ventana;
}

class Ventana : public QWidget
{
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = nullptr);
    ~Ventana();

signals:
    void signal_volver_login();

private slots:
    void on_btnVolver_clicked();

private:
    Ui::Ventana *ui;
};

#endif // VENTANA_H
