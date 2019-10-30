#include "administrador_info_gestion.h"
#include "ui_administrador_info_gestion.h"
#include "QDebug"
administrador_info_gestion::administrador_info_gestion(QString nombre, QString tipo_usr, QString info1, QString info2, QString info3, QString img, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administrador_info_gestion)
{
    ui->setupUi(this);
    mDatabase = QSqlDatabase::database("Connection");
    if(!mDatabase.isOpen()){
          qDebug()<<"Error Base de Datos, esto es: ADMINISTRADOR INFO GESTION";
           return;
    }else{
            qDebug()<<"Base de datos continua abierta, esto es: ADMINISTRADOR INFO GESTION";
    }

    this->nombre = nombre;
    this->tipo_usr = tipo_usr;
    this->info1 = info1;
    this->info2 = info2;
    this->info3 = info3;

    QPixmap imagen(img);
    ui->img->setPixmap(imagen);
    ui->lbl_nombre->setText(this->nombre);
    ui->lbl_tipo_usuario->setText(this->tipo_usr);
    ui->lbl_info1->setText(this->info1);
    ui->lbl_info2->setText(this->info2);
    ui->lbl_info3->setText(this->info3);
}

administrador_info_gestion::~administrador_info_gestion()
{
    delete ui;
}
