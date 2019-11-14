#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include "Widgets/Usuario/registrar.h"
#include "Widgets/Usuario/inicar_sesion.h"
#include "Widgets/Usuario/catalogo_doctores.h"
#include "Widgets/Usuario/catalogo_servicios.h"
#include "Widgets/Administrador/administrador_landpage.h"
#include "Widgets/Administrador/administrador_servicios_hospital.h"
#include "Widgets/Administrador/administador_gestionar_usuarios.h"
#include "Widgets/Administrador/administrador_gestionar_tips.h"
#include "Widgets/Paciente/paciente_landpage.h"
#include "Widgets/Medico/medico_landpage.h"
#include "Widgets/Medico/medico_horario.h"
#include "Widgets/Administrador/administrador_catalogo_cancelacion_cita.h"
#include "Widgets/Medico/medico_solicitudes.h"
#include "Widgets/Usuario/inicar_sesion.h"
#include "Widgets/Paciente/paciente_gestionar_citas.h"
#include "Clases/usuario.h"
#include "Widgets/Medico/medico_informacion.h"
#include "Widgets/Recepcionista/recepcionistalandpage.h"
#include "Widgets/Recepcionista/recepcionista_internados.h"
#include "Widgets/Recepcionista/recepcionista_citas.h"
#include "Widgets/Farmaceutico/farmaceutico_landpage.h"

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setindex(int index);
    QString getNombreUsuario();

private slots:
    void on_btn_iniciar_sesion_clicked();
    void on_btn_registrarse_clicked();
    void on_btn_doctores_info_clicked();
    void on_btn_servicios_clicked();
    void on_btn_servicios_2_clicked();
    void on_btn_inicio_admin_clicked();
    void on_btn_remedios_admin_clicked();
    void on_btn_gestionar_servicios_admin_clicked();
    void on_btn_gestionar_usuarios_admin_clicked();
    void on_btn_gestionar_tips_admin_clicked();
    void on_btn_salir_admin_clicked();
    void on_btn_salir_medico_clicked();
    void on_btn_horario_medico_clicked();
    void on_btn_inicio_medico_clicked();

    void on_pushButton_6_clicked();
    void on_btn_solicitudes_medico_clicked();

    void on_btn_gestionar_citas_clicked();

    void on_btn_informacion_medico_clicked();
    void on_btn_horario_medico_2_clicked();

    void on_btn_citas_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase mDatabase;
    administrador_landpage landpageadministrador;
    Catalogo_servicios catalogo_servicios;
    catalogo_doctores catalogodoctores;
    administrador_servicios_hospital gestionServiciosAdmin;
    administador_gestionar_usuarios gestionUsuariosAdmin;
    administrador_gestionar_tips gestionTipsAdmin;
    paciente_landpage landpagepaciente;
    medico_landPage landpageMedico;
    medico_horario horarioMedico;
    administrador_catalogo_cancelacion_cita cancelacionCatalogoAdmin;
    medico_solicitudes solicitudesMedico;
    inicar_sesion dialogo_iniciar_sesion;
    paciente_gestionar_citas gestionCitas;
    Usuario datosLogin;
    medico_informacion informacionMedico;
    recepcionistaLandpage landpageRecepcionista;
    recepcionista_internados internados;
    recepcionista_citas citas;
    farmaceutico_landpage landpageFarmaceutico;

    int index;
    QString sesion="";
};

#endif // MAINWINDOW_H
