#-------------------------------------------------
#
# Project created by QtCreator 2019-10-24T13:39:30
#
#-------------------------------------------------
QT       += printsupport
QT       += core gui
QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hospital-core
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
    Clases/pdf_cobro.cpp \
    Clases/pdf_receta.cpp \
        Clases/usuario.cpp \
    Widgets/Administrador/administrador_catalogo_remedios.cpp \
    Widgets/Administrador/administrador_crear_remedio.cpp \
        Widgets/Administrador/administrador_crear_servicio.cpp \
        Widgets/Administrador/administrador_crear_usuario.cpp \
    Widgets/Administrador/administrador_horarios_medicos.cpp \
        Widgets/Administrador/administrador_info_servicios.cpp \
    Widgets/Administrador/administrador_modificar_remedio.cpp \
        Widgets/Administrador/administrador_modificar_servicios.cpp \
        Widgets/Administrador/administrador_modificar_usuario.cpp \
    Widgets/Administrador/administrador_tarjeta_remedio.cpp \
    Widgets/Medico/medico_agregar_alergia_operacion_enfermedad.cpp \
    Widgets/Medico/medico_expediente_clinico.cpp \
    Widgets/Medico/medico_generar_receta.cpp \
    Widgets/Medico/medico_info_cita_medica.cpp \
    Widgets/Medico/medico_informacion.cpp \
    Widgets/Medico/medico_modificar.cpp \
    Widgets/Medico/medico_rechazar_cita_medica.cpp \
        Widgets/Medico/medico_solicitudes.cpp \
    Widgets/Medico/medico_tarjeta_cita.cpp \
    Widgets/Medico/medico_tarjeta_citarechazada.cpp \
    Widgets/Medico/tarjeta_permiso.cpp \
    Widgets/Paciente/paciente_crear_cita.cpp \
    Widgets/Paciente/paciente_gestionar_citas.cpp \
        Widgets/Paciente/paciente_landpage.cpp \
    Widgets/Paciente/paciente_reagendar_cita.cpp \
    Widgets/Paciente/paciente_tarjeta_cita.cpp \
    Widgets/Recepcionista/recepcion_tarjeta_citas.cpp \
    Widgets/Recepcionista/recepcionista_citas.cpp \
    Widgets/Recepcionista/recepcionista_cobrar_estancia.cpp \
    Widgets/Recepcionista/recepcionista_tarjeta_cobro.cpp \
    Widgets/Recepcionista/recepcionista_tarjeta_operaciones.cpp \
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
        Widgets/Usuario/recuperar_contra.cpp \
        Widgets/Usuario/registrar.cpp \
        Widgets/Usuario/tarjeta_doctor.cpp \
        Widgets/Usuario/tarjeta_servicios.cpp \
        main.cpp \
        mainwindow.cpp \
    Widgets/Medico/medico_landpage.cpp \
    Widgets/Medico/medico_horario.cpp \
    Widgets/Medico/medico_tarjeta_horario.cpp \
    Widgets/Administrador/administrador_catalogo_cancelacion_cita.cpp \
    Widgets/Administrador/administrador_tarjeta_cancelacion_cita.cpp \
    Widgets/Administrador/administrador_visualizar_cancelacion_cita.cpp \
    Widgets/Recepcionista/recepcionistalandpage.cpp \
    Widgets/Recepcionista/recepcionista_internados.cpp \
    Widgets/Recepcionista/recepcionista_tarjeta_internados.cpp \
    Widgets/Recepcionista/recepcionista_agregar_internado.cpp \
    Widgets/Recepcionista/recepcionista_tarjeta_medicos_internado.cpp \
    Widgets/Recepcionista/recepcionista_tarjeta_pacientes_internados.cpp \
    Widgets/Recepcionista/recepcionista_dialogo_gestionar_internado.cpp \
    Widgets/Paciente/paciente_califica_medico.cpp

HEADERS += \
        Clases/doctor.h \
    Clases/pdf_cobro.h \
    Clases/pdf_receta.h \
        Clases/usuario.h \
    Widgets/Administrador/administrador_catalogo_remedios.h \
    Widgets/Administrador/administrador_crear_remedio.h \
        Widgets/Administrador/administrador_crear_servicio.h \
        Widgets/Administrador/administrador_crear_usuario.h \
    Widgets/Administrador/administrador_horarios_medicos.h \
        Widgets/Administrador/administrador_info_servicios.h \
    Widgets/Administrador/administrador_modificar_remedio.h \
        Widgets/Administrador/administrador_modificar_servicios.h \
        Widgets/Administrador/administrador_modificar_usuario.h \
    Widgets/Administrador/administrador_tarjeta_remedio.h \
    Widgets/Medico/medico_agregar_alergia_operacion_enfermedad.h \
    Widgets/Medico/medico_expediente_clinico.h \
    Widgets/Medico/medico_generar_receta.h \
    Widgets/Medico/medico_info_cita_medica.h \
    Widgets/Medico/medico_informacion.h \
    Widgets/Medico/medico_modificar.h \
    Widgets/Medico/medico_rechazar_cita_medica.h \
        Widgets/Medico/medico_solicitudes.h \
    Widgets/Medico/medico_tarjeta_cita.h \
    Widgets/Medico/medico_tarjeta_citarechazada.h \
    Widgets/Medico/tarjeta_permiso.h \
    Widgets/Paciente/paciente_crear_cita.h \
    Widgets/Paciente/paciente_gestionar_citas.h \
        Widgets/Paciente/paciente_landpage.h \
    Widgets/Paciente/paciente_reagendar_cita.h \
    Widgets/Paciente/paciente_tarjeta_cita.h \
    Widgets/Recepcionista/recepcion_tarjeta_citas.h \
    Widgets/Recepcionista/recepcionista_citas.h \
    Widgets/Recepcionista/recepcionista_cobrar_estancia.h \
    Widgets/Recepcionista/recepcionista_tarjeta_cobro.h \
    Widgets/Recepcionista/recepcionista_tarjeta_operaciones.h \
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
        Widgets/Usuario/recuperar_contra.h \
        Widgets/Usuario/registrar.h \
        Widgets/Usuario/tarjeta_doctor.h \
        Widgets/Usuario/tarjeta_servicios.h \
        mainwindow.h \
    Widgets/Medico/medico_landpage.h \
    Widgets/Medico/medico_horario.h \
    Widgets/Medico/medico_tarjeta_horario.h \
    Widgets/Administrador/administrador_catalogo_cancelacion_cita.h \
    Widgets/Administrador/administrador_tarjeta_cancelacion_cita.h \
    Widgets/Administrador/administrador_visualizar_cancelacion_cita.h \
    Widgets/Recepcionista/recepcionistalandpage.h \
    Widgets/Recepcionista/recepcionista_internados.h \
    Widgets/Recepcionista/recepcionista_tarjeta_internados.h \
    Widgets/Recepcionista/recepcionista_agregar_internado.h \
    Widgets/Recepcionista/recepcionista_tarjeta_medicos_internado.h \
    Widgets/Recepcionista/recepcionista_tarjeta_pacientes_internados.h \
    Widgets/Recepcionista/recepcionista_dialogo_gestionar_internado.h \
    Widgets/Paciente/paciente_califica_medico.h

FORMS += \
    Widgets/Administrador/administrador_catalogo_remedios.ui \
    Widgets/Administrador/administrador_crear_remedio.ui \
        Widgets/Administrador/administrador_crear_servicio.ui \
        Widgets/Administrador/administrador_crear_usuario.ui \
    Widgets/Administrador/administrador_horarios_medicos.ui \
        Widgets/Administrador/administrador_info_servicios.ui \
    Widgets/Administrador/administrador_modificar_remedio.ui \
        Widgets/Administrador/administrador_modificar_servicios.ui \
        Widgets/Administrador/administrador_modificar_usuario.ui \
    Widgets/Administrador/administrador_tarjeta_remedio.ui \
    Widgets/Medico/medico_agregar_alergia_operacion_enfermedad.ui \
    Widgets/Medico/medico_expediente_clinico.ui \
    Widgets/Medico/medico_generar_receta.ui \
    Widgets/Medico/medico_info_cita_medica.ui \
    Widgets/Medico/medico_informacion.ui \
    Widgets/Medico/medico_modificar.ui \
    Widgets/Medico/medico_rechazar_cita_medica.ui \
        Widgets/Medico/medico_solicitudes.ui \
    Widgets/Medico/medico_tarjeta_cita.ui \
    Widgets/Medico/medico_tarjeta_citarechazada.ui \
    Widgets/Medico/tarjeta_permiso.ui \
    Widgets/Paciente/paciente_crear_cita.ui \
    Widgets/Paciente/paciente_gestionar_citas.ui \
        Widgets/Paciente/paciente_landpage.ui \
    Widgets/Paciente/paciente_reagendar_cita.ui \
    Widgets/Paciente/paciente_tarjeta_cita.ui \
    Widgets/Recepcionista/recepcion_tarjeta_citas.ui \
    Widgets/Recepcionista/recepcionista_citas.ui \
    Widgets/Recepcionista/recepcionista_cobrar_estancia.ui \
    Widgets/Recepcionista/recepcionista_tarjeta_cobro.ui \
    Widgets/Recepcionista/recepcionista_tarjeta_operaciones.ui \
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
        Widgets/Usuario/recuperar_contra.ui \
        Widgets/Usuario/registrar.ui \
        Widgets/Usuario/tarjeta_doctor.ui \
        Widgets/Usuario/tarjeta_servicios.ui \
        mainwindow.ui \
    Widgets/Medico/medico_landpage.ui \
    Widgets/Medico/medico_horario.ui \
    Widgets/Medico/medico_tarjeta_horario.ui \
    Widgets/Administrador/administrador_catalogo_cancelacion_cita.ui \
    Widgets/Administrador/administrador_tarjeta_cancelacion_cita.ui \
    Widgets/Administrador/administrador_visualizar_cancelacion_cita.ui \
    Widgets/Recepcionista/recepcionistalandpage.ui \
    Widgets/Recepcionista/recepcionista_internados.ui \
    Widgets/Recepcionista/recepcionista_tarjeta_internados.ui \
    Widgets/Recepcionista/recepcionista_agregar_internado.ui \
    Widgets/Recepcionista/recepcionista_tarjeta_medicos_internado.ui \
    Widgets/Recepcionista/recepcionista_tarjeta_pacientes_internados.ui \
    Widgets/Recepcionista/recepcionista_dialogo_gestionar_internado.ui \
    Widgets/Paciente/paciente_califica_medico.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES +=
