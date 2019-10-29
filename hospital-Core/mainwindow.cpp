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

    mDatabase = QSqlDatabase::database("Connection");
    if (!mDatabase.isOpen()){
        qDebug() << "ERROR";
    }else{
        qDebug() << "Base de datos conectada exitosamente";
    }

    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->stackedWidget->insertWidget(1, &landpageadministrador);
    ui->stackedWidget->insertWidget(2, &catalogo_servicios);
    ui->stackedWidget->insertWidget(3, &catalogodoctores);

}

MainWindow::MainWindow(QWidget *parent, int tipo): QMainWindow(parent),
ui(new Ui::MainWindow){
    ui->setupUi(this);

    mDatabase = QSqlDatabase::database("Connection");
    if (!mDatabase.isOpen()){
        qDebug() << "ERROR, esto es constructor MW 2";
    }else{
        qDebug() << "Base de datos conectada exitosamente MAINWUNDOW C2";
    }

    this->index = tipo;
    qDebug()<<"Tipo Usuario MW: " << this->index;
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

    if(this->index == 3){
        ui->stackedWidget->setCurrentIndex(1);
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
