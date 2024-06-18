#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QImage>
#include <QPainter>
#include <QTimer>

class ImageLabel : public QLabel {
public:
    ImageLabel(const QImage &image) : image(image) {}

protected:
    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.drawImage(rect(), image);
    }

private:
    QImage image;
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QImage imagen("D:/Usuarios/Maxi/Downloads/logopg.jpg");
    ImageLabel qlabel(imagen);

    qlabel.showMaximized();

    QTimer::singleShot(3000, &app, [](){ QApplication::quit(); });

    return app.exec();
}
