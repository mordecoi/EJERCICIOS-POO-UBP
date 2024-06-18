#include "admindb.h"

#include <QSqlQuery>
#include <QVariant>
#include <QDebug>

AdminDB *AdminDB::instance = nullptr;

AdminDB *AdminDB::getInstance() {
    if (instance == nullptr) {
        instance = new AdminDB;
    }
    return instance;
}

AdminDB::AdminDB(QObject *parent) : QObject(parent) {
    database = QSqlDatabase::addDatabase("QSQLITE");
}

bool AdminDB::connectDatabase(QString sqliteFile) {
    database.setDatabaseName(sqliteFile);

    if (database.open()) {
        qDebug() << "Base de Datos abierta!";
        return true;
    }

    qDebug() << "No se pudo abrir la Base de Datos.";
    return false;
}

QSqlDatabase AdminDB::getDatabase() {
    return database;
}

bool AdminDB::validateUser(QString table, QString username, QString password) {
    qDebug() << "Usuario: " << username;
    qDebug() << "Clave: " << password;

    if (database.open()) {
        qDebug() << "Validando Usuario...";

        QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Md5).toHex();
        QSqlQuery query = database.exec("SELECT nombre, apellido FROM " + table +
                                        " WHERE usuario = '" + username + "' AND clave = '" + hash + "'");

        while (query.next()) {
            qDebug() << query.value(0).toString() << " " << query.value(1).toString();
            qDebug() << "Usuario encontrado.";
            return true;
        }
    }

    qDebug() << "Usuario no encontrado.";
    return false;
}

void AdminDB::insertUser(QString table, QString username, QString password, QString name, QString surname) {
    qDebug() << "Intentando insertar usuario..." << username;

    if (database.open()) {
        qDebug() << "Insertando Usuario...";

        QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Md5).toHex();
        QSqlQuery query = database.exec("INSERT INTO " + table + " (usuario, clave, nombre, apellido) VALUES "
                                                                 "('" + username + "','" + hash + "','" + name + "','" + surname + "')");

        QSqlQuery queryTwo = database.exec("SELECT nombre, apellido FROM " + table +
                                           " WHERE usuario = '" + username + "' AND clave = '" + hash + "'");

        while (queryTwo.next()) {
            qDebug() << "Usuario ingresado exitosamente a la Base de Datos!";
            return;
        }
    }

    qDebug() << "No se pudo insertar el usuario..." << username;
}

bool AdminDB::userExists(QString table, QString username) {
    if (database.open()) {
        qDebug() << "Verificando si el usuario existe...";

        QSqlQuery query = database.exec("SELECT usuario FROM " + table + " WHERE usuario = '" + username + "'");

        while (query.next()) {
            qDebug() << query.value(0).toString();
            return true;
        }
    }

    return false;
}

QSqlQuery AdminDB::getUsers(QString table) {
    if (database.open()) {
        qDebug() << "Obteniendo todos los usuarios...";

        QSqlQuery query = database.exec("SELECT * FROM " + table);
        return query;
    }

    QSqlQuery emptyQuery;
    emptyQuery.clear();
    return emptyQuery;
}
