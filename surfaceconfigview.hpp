#ifndef SURFACECONFIGVIEW_HPP
#define SURFACECONFIGVIEW_HPP

#include <QWidget>
#include "xmlconnection.hpp"

class SurfaceConfigView : public QWidget
{
    Q_OBJECT

    VTC::XmlConnection* xmlConnection;
public:
    explicit SurfaceConfigView(QWidget *parent = nullptr);

public slots:
    void createButtonClicked(bool checked);

};

#endif // SURFACECONFIGVIEW_HPP
