#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QDebug>
#include "Widgets/Usuario/registro.h"

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

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
