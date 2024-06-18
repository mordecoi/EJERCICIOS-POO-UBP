#include "admin_db.h"

admin_db::admin_db()
{
    QString dbpath = "../../../usuarios.sqlite";

    QSqlDatabase dbMan = QSqlDatabase::addDatabase("QSQLITE");
    dbMan.setDatabaseName("usuarios.sqlite");
    if(!dbMan.open())
        qDebug() << "No se pudo abrir la base de datos.";
}

void admin_db::ejecutarConsulta(QString &consulta)
{
    QSqlQuery query;
    query.prepare(consulta);

    if(query.exec())
    {
        qDebug() << "La consulta se ejecuto exitosamente.\n";

        // Mostrar los resultados
        while (query.next())
        {
            QSqlRecord record = query.record();
            QString row;
            for (int i = 0; i < record.count(); i++)
            {
                row += QString("%1: %2 | ").arg(record.fieldName(i)).arg(query.value(i).toString());
            }
            qDebug() << row;
        }
    }
    else
    {
        qDebug() << "La consulta no se pudo ejecutar.\n";
    }
}

void admin_db::agregarUsuario(QString usuario, QString clave)
{
    QString query = "INSERT INTO pruebaUsuarios (usuario, clave) VALUES ('";
    query.append(usuario);
    query.append("', '");
    query.append(clave);
    query.append("')");

    ejecutarConsulta(query);
}
