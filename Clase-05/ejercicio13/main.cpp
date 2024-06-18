#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>

int main(int argc, char** argv) {
    QApplication a(argc, argv);

    QWidget* ventana = new QWidget;
    ventana->setWindowTitle("Volumen");
    ventana->resize(300, 50);

    QSpinBox* spinBox = new QSpinBox;
    QSlider* slider = new QSlider(Qt::Horizontal);
    spinBox->setRange(0, 100);
    slider->setRange(0, 100);

    // Connect slider and spinBox for synchronized updates
    QObject::connect(slider, &QSlider::valueChanged, spinBox, &QSpinBox::setValue);
    QObject::connect(spinBox, &QSpinBox::valueChanged, slider, &QSlider::setValue);

    // Set initial value (optional, can be removed if not needed)
    spinBox->setValue(15);

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(spinBox);
    layout->addWidget(slider);
    ventana->setLayout(layout);

    // Update window title whenever the slider value changes
    QObject::connect(slider, &QSlider::valueChanged, [&ventana](int value) {
        ventana->setWindowTitle(QString::number(value));
    });

    ventana->setVisible(true);

    return a.exec();
}
