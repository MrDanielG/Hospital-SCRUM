#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include "Widgets/Usuario/registrar.h"
#include "Widgets/Usuario/inicar_sesion.h"
#include "Widgets/Usuario/catalogo_doctores.h"
#include "Widgets/Administrador/administrador_landpage.h"
#include "Widgets/Usuario/catalogo_servicios.h"

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    explicit MainWindow(QWidget *parent, int);
    ~MainWindow();
    void setindex(int index);

private slots:
    void on_btn_iniciar_sesion_clicked();
    void on_btn_registrarse_clicked();
    void on_btn_doctores_info_clicked();

    void on_btn_servicios_clicked();

    void on_btn_servicios_2_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase mDatabase;
    administrador_landpage landpageadministrador;
    Catalogo_servicios catalogo_servicios;

    int index;
};

#endif // MAINWINDOW_H
