#include "surfaceconfigview.hpp"
#include "surfaceinputgroupbox.hpp"
#include <QVBoxLayout>

SurfaceConfigView::SurfaceConfigView(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout* layout = new QVBoxLayout(this);

    layout->addWidget(new SurfaceInputGroupBox(this, "A"));
    layout->addWidget(new SurfaceInputGroupBox(this, "B"));
    layout->addWidget(new SurfaceInputGroupBox(this, "C"));
    layout->addWidget(new SurfaceInputGroupBox(this, "D"));
    layout->addWidget(new SurfaceInputGroupBox(this, "E"));

    this->setLayout(layout);
}
