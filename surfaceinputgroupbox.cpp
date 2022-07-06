#include "surfaceinputgroupbox.hpp"

#include <QComboBox>
#include <QLabel>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QTimeEdit>

SurfaceInputGroupBox::SurfaceInputGroupBox(QWidget *parent, QString name, QColor backgroundColor) : QGroupBox(parent)
{
    QPalette palette = QPalette{};
    palette.setColor(QPalette::Window, backgroundColor);
    this->setAutoFillBackground(true);
    this->setPalette(palette);

    this->setTitle(name);

    auto* mainLayout = new QVBoxLayout;

    auto* upperInputRowLayout = new QHBoxLayout;
    upperInputRowLayout->addWidget(new QLabel{"Projekt", this});
    upperInputRowLayout->addWidget(new QComboBox{this});
    upperInputRowLayout->addWidget(new QLabel{"Phase", this});
    upperInputRowLayout->addWidget(new QComboBox{this});
    upperInputRowLayout->addWidget(new QLabel{"Tätigkeit", this});
    upperInputRowLayout->addWidget(new QComboBox{this});
    upperInputRowLayout->addStretch(1);
    mainLayout->addLayout(upperInputRowLayout);

    auto* lowerInputRowLayout = new QHBoxLayout;
    lowerInputRowLayout->addWidget(new QLabel{"Ort", this});
    lowerInputRowLayout->addWidget(new QLineEdit{this});
    lowerInputRowLayout->addWidget(new QLabel{"Beschreibung", this});
    lowerInputRowLayout->addWidget(new QLineEdit{this});
    lowerInputRowLayout->addWidget(new QLabel{"Zeit", this});
    lowerInputRowLayout->addWidget(new QTimeEdit{this});
    lowerInputRowLayout->addStretch(1);
    mainLayout->addLayout(lowerInputRowLayout);

    this->setLayout(mainLayout);
}
