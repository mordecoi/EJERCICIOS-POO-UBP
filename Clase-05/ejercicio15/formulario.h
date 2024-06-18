#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

class Formulario : public QWidget
{
    Q_OBJECT

private:
    QLabel *labelLegajo, *labelNombre, *labelApellido, *labelNomCaptcha, *labelCaptcha;
    QLineEdit *lineEditLegajo, *lineEditNombre, *lineEditApellido, *lineEditCaptcha;
    QPushButton *pushButtonAlta;
    QGridLayout *layout;
    int numCaptcha;

public:
    Formulario();
    void generarCaptcha();
    void cerrarLogin();

private slots:
    void validarCaptcha();

signals:
    void signalCerrarLogin();
};

#endif // FORMULARIO_H
