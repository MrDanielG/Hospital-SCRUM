#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QDebug>
#include "Widgets/Usuario/registrar.h"
#include "Widgets/Usuario/inicar_sesion.h"
#include "Widgets/Usuario/catalogo_doctores.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{
    ui->setupUi(this);


#ifdef Q_OS_WIN
  mDatabase = QSqlDatabase::database("Connection");
#elif defined(Q_OS_MAC)
  mDatabase = QSqlDatabase::database();
  mDatabase.setHostName("localhost");
  mDatabase.setDatabaseName("hospital");
  mDatabase.setUserName("root");
  mDatabase.setPassword("luisdrew1394");
#endif

    ui->stackedWidget->setCurrentIndex(1);
    ui->stackedWidget_2->setCurrentIndex(1);
    ui->stackedWidget->insertWidget(1, &landpageadministrador);
    ui->stackedWidget->insertWidget(2, &catalogo_servicios);
    ui->stackedWidget->insertWidget(3, &catalogodoctores);
    ui->stackedWidget->insertWidget(4, &gestionServiciosAdmin);
    ui->stackedWidget->insertWidget(5, &gestionUsuariosAdmin);
    ui->stackedWidget->insertWidget(6, &gestionTipsAdmin);
    ui->stackedWidget->insertWidget(7, &medicoLandpage);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setindex(int index){
    this->index = index;
}

void MainWindow::on_btn_iniciar_sesion_clicked()
{
    inicar_sesion dialogo_iniciar_sesion;
    dialogo_iniciar_sesion.exec();
    this->index = dialogo_iniciar_sesion.getindex(); //Retorno tipo de usuario a MainWindow para abrir interfaz correcta

    if(this->index == 1){
        /*Aqui deben poner el index del landpage al que quieran visualizar
         * 1 = Medico
         * 2 = Paciente
         * 3 = Administrador
         * 4 = Farmaceutico
         * 5 = Staff
         *
         * esto se hace para todos los else if dependiendo el caso
        */
        ui->stackedWidget->setCurrentIndex(7);
    }
    else if(this->index == 2){

    }
    else if(this->index == 3){
        ui->stackedWidget->setCurrentIndex(1);
        //Aqui se cambia el index del navegador, se hace lo mismo para todos
        ui->stackedWidget_2->setCurrentIndex(1);
    }
    else if(this->index == 4){

    }
    else if(this->index == 5){

    }



}

void MainWindow::on_btn_registrarse_clicked(){
    registrar dialogo_registro;
    dialogo_registro.exec();
}

void MainWindow::on_btn_doctores_info_clicked(){
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_btn_servicios_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_btn_servicios_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_btn_inicio_admin_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_btn_remedios_admin_clicked()
{
    qDebug()<<"Aun no la haces prro";
}

void MainWindow::on_btn_gestionar_servicios_admin_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_btn_gestionar_usuarios_admin_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_btn_gestionar_tips_admin_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_btn_salir_admin_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget_2->setCurrentIndex(0);
}
