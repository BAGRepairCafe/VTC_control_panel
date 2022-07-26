#include "mainwindow.hpp"
#include "settingshandler.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    SettingsHandler handler{};

    w.show();

    return a.exec();
}
