#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "surfaceconfigview.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    auto centralWidget = new SurfaceConfigView();
    setCentralWidget(centralWidget);
    this->setMinimumSize(QSize{500, 500});
}

MainWindow::~MainWindow()
{
}

