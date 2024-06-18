#ifndef LABEL_H
#define LABEL_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QFont>
#include <QDebug>

class ClickableLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ClickableLabel(const QString& text = "", QWidget* parent = nullptr);
    ~ClickableLabel() override;

protected:
    void mousePressEvent(QMouseEvent* event) override;

signals:
    void clicked();

};

#endif // LABEL_H
