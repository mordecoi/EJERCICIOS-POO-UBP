#ifndef ADMIN_DB_H
#define ADMIN_DB_H

#include <QDir>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QString>

class admin_db : public QObject
{
    Q_OBJECT
public:
    admin_db();
    void ejecutarConsulta(QString &consulta);
    void agregarUsuario(QString usuario, QString clave);
    void validarUsuario(QString usuario, QString clave);
private:

};

#endif // ADMIN_DB_H
