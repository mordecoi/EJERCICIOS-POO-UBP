#ifndef ADMIN_H
#define ADMIN_H

#include <QWidget>
#include <QTreeWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QByteArray>
#include <QCryptographicHash>
#include <QString>
#include <QDebug>

#include <admindb.h>

namespace Ui {
class Admin;
}

class Admin : public QWidget
{
    Q_OBJECT
public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();
    void displayTree();
    QSqlQuery getData();

private:
    Ui::Admin *uiWidgetAdmin;
    AdminDB* dbAdminDb;
    QSqlQuery sqlQuery;
};

#endif // ADMIN_H
