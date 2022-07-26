#include "../io/settingshandler.hpp"
#include "surfaceconfigview.hpp"
#include "surfaceinputgroupbox.hpp"
#include <QPushButton>
#include <QVBoxLayout>

SurfaceConfigView::SurfaceConfigView(QWidget *parent) : QWidget(parent),
    xmlConnection{new VTC::XmlConnection{QUrl{"https://erp-dev.brockhaus-ag.de"}, this}}
{
    std::vector<CubeSurfaceInfo> infos = SettingsHandler::getInstance().get_surface_infos();
    assert(infos.size() >= 5);

    QVBoxLayout* layout = new QVBoxLayout(this);

    auto inputGroupA = new SurfaceInputGroupBox(infos[0], "Oberfläche A", QColor::fromRgbF(255, 0, 0, 0.2), this);

    layout->addWidget(inputGroupA);
    connect(inputGroupA, &SurfaceInputGroupBox::input,
            this, [](CubeSurfaceInfo newInfo){SettingsHandler::getInstance().set_surface_info(0, newInfo);});

    layout->addWidget(new SurfaceInputGroupBox(infos[1],"Oberfläche B", QColor::fromRgbF(0, 255, 0, 0.2), this));
    connect(inputGroupA, &SurfaceInputGroupBox::input,
            this, [](CubeSurfaceInfo newInfo){SettingsHandler::getInstance().set_surface_info(1, newInfo);});

    layout->addWidget(new SurfaceInputGroupBox(infos[2], "Oberfläche C", QColor::fromRgbF(0, 0, 255, 0.2), this));
    connect(inputGroupA, &SurfaceInputGroupBox::input,
            this, [](CubeSurfaceInfo newInfo){SettingsHandler::getInstance().set_surface_info(2, newInfo);});

    layout->addWidget(new SurfaceInputGroupBox(infos[3], "Oberfläche D", QColor::fromRgbF(255, 255, 0, 0.2), this));
    connect(inputGroupA, &SurfaceInputGroupBox::input,
            this, [](CubeSurfaceInfo newInfo){SettingsHandler::getInstance().set_surface_info(3, newInfo);});

    layout->addWidget(new SurfaceInputGroupBox(infos[4], "Oberfläche E", QColor::fromRgbF(255, 0, 255, 0.2), this));
    connect(inputGroupA, &SurfaceInputGroupBox::input,
            this, [](CubeSurfaceInfo newInfo){SettingsHandler::getInstance().set_surface_info(4, newInfo);});

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
