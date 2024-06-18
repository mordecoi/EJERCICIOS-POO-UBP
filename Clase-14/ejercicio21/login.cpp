#include "login.h"
#include "ui_login.h"
#include "ventana.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    // Open the database connection
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("D:/Usuarios/Maxi/Desktop/POO/subidagithub/ejercicio21/usuarios.sqlite");

    if (!m_db.open()) {
        QMessageBox::critical(this, "Database Error", m_db.lastError().text());
    }
}

Login::~Login()
{
    m_db.close(); // Close the database connection
    delete ui;
}

void Login::on_btnLogin_clicked()
{
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter both username and password.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM usuarios WHERE usuario = :username AND clave = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (query.exec()) {
        if (query.next()) {
            emit signal_login_successful();
        } else {
            QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
        }
    } else {
        QMessageBox::critical(this, "Database Error", query.lastError().text());
    }
}
