#ifndef ADMINDB_H
#define ADMINDB_H

#include <QObject>
#include <QSqlDatabase>
#include <QString>
#include <QByteArray>
#include <QCryptographicHash>

class AdminDB : public QObject
{
    Q_OBJECT
public:
    static AdminDB *getInstance();
    explicit AdminDB(QObject *parent = nullptr);

    bool connectDatabase(QString sqliteFile);
    QSqlDatabase getDatabase();

    bool validateUser(QString table, QString username, QString password);
    void insertUser(QString table, QString username, QString password, QString name, QString surname);
    bool userExists(QString table, QString username);
    QSqlQuery getUsers(QString table);

private:
    QSqlDatabase database;

    static AdminDB* instance;
};

#endif // ADMINDB_H
