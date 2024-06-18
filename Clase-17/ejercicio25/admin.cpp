#include "admin.h"
#include "ui_admin.h"
#include <QMessageBox>

Admin::Admin(QWidget *parent)
    : QWidget(parent)
    , uiWidgetAdmin(new Ui::Admin)
{
    uiWidgetAdmin->setupUi(this);
    this->setWindowTitle("Base_de_Datos");
    dbAdminDb = new AdminDB();
    sqlQuery = getData();
    displayTree();

    this->show();
    qDebug() << this->width() << this->height();
}

Admin::~Admin()
{
    delete uiWidgetAdmin;
}

void Admin::displayTree() {
    uiWidgetAdmin->tree->setColumnCount(5);

    QStringList headers;
    headers << "ID" << "Usuario" << "Clave" << "Nombre" << "Apellido";
    uiWidgetAdmin->tree->setHeaderLabels(headers);

    while (sqlQuery.next()) {
        QTreeWidgetItem* treeWidgetItem = new QTreeWidgetItem();
        qDebug() << sqlQuery.value(0).toString() << sqlQuery.value(1).toString() << sqlQuery.value(2).toString() << sqlQuery.value(3).toString() << sqlQuery.value(4).toString();
        treeWidgetItem->setText(0, sqlQuery.value(0).toString());
        treeWidgetItem->setText(1, sqlQuery.value(1).toString());
        treeWidgetItem->setText(2, sqlQuery.value(2).toString());
        treeWidgetItem->setText(3, sqlQuery.value(3).toString());
        treeWidgetItem->setText(4, sqlQuery.value(4).toString());
        qDebug() << "Procesando...";
        treeWidgetItem->setFlags(treeWidgetItem->flags() | Qt::ItemIsEditable);
        uiWidgetAdmin->tree->addTopLevelItem(treeWidgetItem);
    }
    QMessageBox::information(this, "Procesando datos", "Procesando...");
}

QSqlQuery Admin::getData() {
    if (dbAdminDb->connectDatabase("D:/Usuarios/Maxi/Desktop/POO/subidagithub/ejercicio25/usuariosv2.sqlite")) {
        qDebug() << "Consiguiendo los Datos";
        return dbAdminDb->getUsers("usuarios");
    } else {
        qDebug() << "No se pudo conectar a la Base de Datos";
    }
    return QSqlQuery();
}
