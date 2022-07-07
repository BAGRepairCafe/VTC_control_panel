#include "surfaceconfigview.hpp"
#include "surfaceinputgroupbox.hpp"
#include <QPushButton>
#include <QVBoxLayout>

SurfaceConfigView::SurfaceConfigView(QWidget *parent) : QWidget(parent),
    xmlConnection{new VTC::XmlConnection{QUrl{"https://erp-dev.brockhaus-ag.de"}, this}}
{


    QVBoxLayout* layout = new QVBoxLayout(this);

    layout->addWidget(new SurfaceInputGroupBox(this, "Oberfläche A", QColor::fromRgbF(255, 0, 0, 0.2)));
    layout->addWidget(new SurfaceInputGroupBox(this, "Oberfläche B", QColor::fromRgbF(0, 255, 0, 0.2)));
    layout->addWidget(new SurfaceInputGroupBox(this, "Oberfläche C", QColor::fromRgbF(0, 0, 255, 0.2)));
    layout->addWidget(new SurfaceInputGroupBox(this, "Oberfläche D", QColor::fromRgbF(255, 255, 0, 0.2)));
    layout->addWidget(new SurfaceInputGroupBox(this, "Oberfläche E", QColor::fromRgbF(255, 0, 255, 0.2)));
    auto createButton = new QPushButton{"Leistungen erstellen", this};
    connect(createButton, &QAbstractButton::clicked,
            this, &SurfaceConfigView::createButtonClicked);
    layout->addWidget(createButton);

    this->setLayout(layout);
}

void SurfaceConfigView::createButtonClicked([[maybe_unused]] bool checked)
{
    auto resp = xmlConnection->authenticate("", "");
}
