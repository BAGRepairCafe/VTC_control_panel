#ifndef SURFACEINPUTGROUPBOX_H
#define SURFACEINPUTGROUPBOX_H

#include <QColor>
#include <QGroupBox>

#include "../model/cubesurfaceinfo.hpp"

class SurfaceInputGroupBox : public QGroupBox
{
    Q_OBJECT
    CubeSurfaceInfo surfaceInfo;
public:
    explicit SurfaceInputGroupBox(CubeSurfaceInfo surfaceInfo, QString title = "", QColor backgroundColor = QColor::fromRgbF(0, 0, 0, 0.0), QWidget *parent = nullptr);
signals:
    void input(CubeSurfaceInfo);
};

#endif // SURFACEINPUTGROUPBOX_H
