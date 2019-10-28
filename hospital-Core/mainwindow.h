#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include "Widgets/Usuario/registrar.h"
#include "Widgets/Usuario/inicar_sesion.h"
#include "Widgets/Usuario/catalogo_doctores.h"

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

private slots:
    void on_btn_iniciar_sesion_clicked();
    void on_btn_registrarse_clicked();

    void on_btn_doctores_info_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase mDatabase;
    registrar ventanaRegistro;
    inicar_sesion ventanaSesion;
    catalogo_doctores catalogo_doctores;

};

#endif // MAINWINDOW_H
