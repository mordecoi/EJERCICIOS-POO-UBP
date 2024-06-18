#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QFont>
#include <QDebug>
#include <QMessageBox>

#include "admindb.h"

class Ventana : public QWidget
{
    Q_OBJECT
public:
    explicit Ventana(QWidget *parent = nullptr);

private:
    QGridLayout* layout;
    QLabel* lblUsuario, *lblPassword, *lblNombre, *lblApellido;
    QLineEdit* leUsuario, *lePassword, *leNombre, *leApellido;
    QPushButton* btnRegistrar;
    AdminDB* admindb;

private slots:
    void slotRegistrar();
};

#endif // VENTANA_H
