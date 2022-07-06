#ifndef SURFACEINPUTGROUPBOX_H
#define SURFACEINPUTGROUPBOX_H

#include <QColor>
#include <QGroupBox>

class SurfaceInputGroupBox : public QGroupBox
{
    Q_OBJECT
public:
    explicit SurfaceInputGroupBox(QWidget *parent = nullptr, QString title = "", QColor backgroundColor = QColor::fromRgbF(0, 0, 0, 0.0));
signals:

};

#endif // SURFACEINPUTGROUPBOX_H
