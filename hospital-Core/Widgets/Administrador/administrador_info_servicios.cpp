#include "administrador_info_servicios.h"
#include "ui_administrador_info_servicios.h"
#include "QDebug"
administrador_info_servicios::administrador_info_servicios(QString id, QString servicio, QString info, QString foto, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administrador_info_servicios)
{
    ui->setupUi(this);
    mDatabase = QSqlDatabase::database("Connection");
    if(!mDatabase.isOpen()){
          qDebug()<<"Error Base de Datos, esto es: ADMINISTRADOR INFO SERVICIOS";
           return;
    }else{
            qDebug()<<"Base de datos continua abierta, esto es: ADMINISTRADOR INFO SERVICIOS";
    }

    //Se insertan los valores a la UI
    ui->nombre_servicio->setText(servicio);
    ui->info_servicio->setPlainText(info);
    QPixmap img(foto);
    ui->img->setPixmap(img);
}

administrador_info_servicios::~administrador_info_servicios()
{
    delete ui;
}
