#include "surfaceconfigview.hpp"
#include "surfaceinputgroupbox.hpp"
#include <QPushButton>
#include <QVBoxLayout>

SurfaceConfigView::SurfaceConfigView(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout* layout = new QVBoxLayout(this);

    layout->addWidget(new SurfaceInputGroupBox(this, "Oberfläche A", QColor::fromRgbF(255, 0, 0, 0.2)));
    layout->addWidget(new SurfaceInputGroupBox(this, "Oberfläche B", QColor::fromRgbF(0, 255, 0, 0.2)));
    layout->addWidget(new SurfaceInputGroupBox(this, "Oberfläche C", QColor::fromRgbF(0, 0, 255, 0.2)));
    layout->addWidget(new SurfaceInputGroupBox(this, "Oberfläche D", QColor::fromRgbF(255, 255, 0, 0.2)));
    layout->addWidget(new SurfaceInputGroupBox(this, "Oberfläche E", QColor::fromRgbF(255, 0, 255, 0.2)));
    layout->addWidget(new QPushButton{"Leistungen erstellen", this});

    this->setLayout(layout);
}
