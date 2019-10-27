#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include "Widgets/Usuario/registrar.h"
#include "Widgets/Usuario/inicar_sesion.h"

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

private:
    Ui::MainWindow *ui;
    QSqlDatabase mDatabase;
    registrar ventanaRegistro;
    inicar_sesion ventanaSesion;

};

#endif // MAINWINDOW_H
