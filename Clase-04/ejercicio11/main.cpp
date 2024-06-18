#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Crear objetos de diferentes clases
    QLabel qlabel("Etiqueta");
    QWidget qwidget;
    QPushButton qpushbutton("Botón");
    QLineEdit qlineEdit;

    // Mostrar cada objeto
    qlabel.show();
    qwidget.show();
    qpushbutton.show();
    qlineEdit.show();

    return app.exec();
}
