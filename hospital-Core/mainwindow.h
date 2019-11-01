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

    int index;
};

#endif // MAINWINDOW_H
