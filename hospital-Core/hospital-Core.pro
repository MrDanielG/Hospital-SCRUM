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
        Clases/doctor.cpp \
        Clases/usuario.cpp \
        Widgets/Administrador/administrador_crear_usuario.cpp \
        Widgets/Administrador/administrador_modificar_usuario.cpp \
        Widgets/Usuario/catalogo_doctores.cpp \
        Widgets/Administrador/administador_gestionar_usuarios.cpp \
        Widgets/Administrador/administrador_crear_tips.cpp \
        Widgets/Administrador/administrador_gestionar_tips.cpp \
        Widgets/Administrador/administrador_info_gestion.cpp \
        Widgets/Administrador/administrador_info_tip.cpp \
        Widgets/Administrador/administrador_landpage.cpp \
        Widgets/Administrador/administrador_servicios_hospital.cpp \
        Widgets/Administrador/administrador_tarjeta_gestion.cpp \
        Widgets/Usuario/catalogo_servicios.cpp \
        Widgets/Administrador/administrador_tarjeta_servicios.cpp \
        Widgets/Usuario/info_medico.cpp \
        Widgets/Usuario/info_servicios.cpp \
        Widgets/Usuario/inicar_sesion.cpp \
        Widgets/Usuario/registrar.cpp \
        Widgets/Usuario/tarjeta_doctor.cpp \
        Widgets/Usuario/tarjeta_servicios.cpp \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        Clases/doctor.h \
        Clases/usuario.h \
        Widgets/Administrador/administrador_crear_usuario.h \
        Widgets/Administrador/administrador_modificar_usuario.h \
        Widgets/Usuario/catalogo_doctores.h \
        Widgets/Administrador/administador_gestionar_usuarios.h \
        Widgets/Administrador/administrador_crear_tips.h \
        Widgets/Administrador/administrador_gestionar_tips.h \
        Widgets/Administrador/administrador_info_gestion.h \
        Widgets/Administrador/administrador_info_tip.h \
        Widgets/Administrador/administrador_landpage.h \
        Widgets/Administrador/administrador_servicios_hospital.h \
        Widgets/Administrador/administrador_tarjeta_gestion.h \
        Widgets/Usuario/catalogo_servicios.h \
        Widgets/Administrador/administrador_tarjeta_servicios.h \
        Widgets/Usuario/info_medico.h \
        Widgets/Usuario/info_servicios.h \
        Widgets/Usuario/inicar_sesion.h \
        Widgets/Usuario/registrar.h \
        Widgets/Usuario/tarjeta_doctor.h \
        Widgets/Usuario/tarjeta_servicios.h \
        mainwindow.h

FORMS += \
        Widgets/Administrador/administrador_crear_usuario.ui \
        Widgets/Administrador/administrador_modificar_usuario.ui \
        Widgets/Usuario/catalogo_doctores.ui \
        Widgets/Administrador/administador_gestionar_usuarios.ui \
        Widgets/Administrador/administrador_crear_tips.ui \
        Widgets/Administrador/administrador_gestionar_tips.ui \
        Widgets/Administrador/administrador_info_gestion.ui \
        Widgets/Administrador/administrador_info_tip.ui \
        Widgets/Administrador/administrador_landpage.ui \
        Widgets/Administrador/administrador_servicios_hospital.ui \
        Widgets/Administrador/administrador_tarjeta_gestion.ui \
        Widgets/Usuario/catalogo_servicios.ui \
        Widgets/Administrador/administrador_tarjeta_servicios.ui \
        Widgets/Usuario/info_medico.ui \
        Widgets/Usuario/info_servicios.ui \
        Widgets/Usuario/inicar_sesion.ui \
        Widgets/Usuario/registrar.ui \
        Widgets/Usuario/tarjeta_doctor.ui \
        Widgets/Usuario/tarjeta_servicios.ui \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES +=
