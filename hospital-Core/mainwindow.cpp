#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QDebug>
#include "Widgets/Usuario/registro.h"
#include "Widgets/Usuario/inicar_sesion.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mDatabase = QSqlDatabase::database("Connection");
    if(!mDatabase.isOpen()){
           qDebug()<<"ERROR";
    }else{
            qDebug()<<"Base de datos conectada exitosamente";
    }

    ui->stackedWidget->insertWidget(1, &ventanaRegistro);

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_btn_iniciar_sesion_clicked(){
    inicar_sesion dialogo_iniciar_sesion;
    dialogo_iniciar_sesion.exec();

}
