#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

signals:
    void signal_login_successful();

private slots:
    void on_btnLogin_clicked();

private:
    Ui::Login *ui;
    QSqlDatabase m_db;
};

#endif // LOGIN_H
