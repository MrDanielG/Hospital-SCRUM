#-------------------------------------------------
#
# Project created by QtCreator 2019-10-24T13:39:30
#
#-------------------------------------------------

QT       += core gui
QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hospital-Core
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        Widgets/Administrador/administador_gestionar_usuarios.cpp \
        Widgets/Administrador/administrador_landpage.cpp \
        Widgets/Administrador/administrador_tarjeta_gestion.cpp \
        Widgets/Usuario/inicar_sesion.cpp \
        Widgets/Usuario/registro.cpp \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        Widgets/Administrador/administador_gestionar_usuarios.h \
        Widgets/Administrador/administrador_landpage.h \
        Widgets/Administrador/administrador_tarjeta_gestion.h \
        Widgets/Usuario/inicar_sesion.h \
        Widgets/Usuario/registro.h \
        mainwindow.h

FORMS += \
        Widgets/Administrador/administador_gestionar_usuarios.ui \
        Widgets/Administrador/administrador_landpage.ui \
        Widgets/Administrador/administrador_tarjeta_gestion.ui \
        Widgets/Usuario/inicar_sesion.ui \
        Widgets/Usuario/registro.ui \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES +=
