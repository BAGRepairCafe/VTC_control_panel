QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

macx: {
QMAKE_MACOSX_DEPLOYMENT_TARGET = 12.03
}

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/main.cpp \
    src/widgets/mainwindow.cpp \
    src/model/cubesurfaceinfo.cpp \
    src/io/settingshandler.cpp \
    src/io/xmlconnection.cpp \
    src/widgets/surfaceconfigview.cpp \
    src/widgets/surfaceinputgroupbox.cpp

HEADERS += \
    libs/json.hpp \
    src/widgets/mainwindow.hpp \
    src/model/cubesurfaceinfo.hpp \
    src/io/settingshandler.hpp \
    src/io/xmlconnection.hpp \
    src/widgets/surfaceconfigview.hpp \
    src/widgets/surfaceinputgroupbox.hpp

FORMS +=

TRANSLATIONS += \
    VTC_control_panel_de_DE.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    src/README.md
