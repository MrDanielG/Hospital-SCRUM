#include "administador_gestionar_usuarios.h"
#include "ui_administador_gestionar_usuarios.h"
#include "Widgets/Administrador/administrador_tarjeta_gestion.h"
#include "QMessageBox"
administador_gestionar_usuarios::administador_gestionar_usuarios(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::administador_gestionar_usuarios)
{
    ui->setupUi(this);
    mDatabase = QSqlDatabase::database("Connection");
    if(!mDatabase.isOpen()){
           qDebug()<<"ERROR con Base de Datos, esto es: GESTIONAR USUARIOS";
           return;
    }else{
            qDebug()<<"Base de datos continua abierta, esto es: GESTIONAR USUARIOS";
    }

    int i=0;
    int row = 0;
    int col = 0;
    int x = 0;
    //while (query.next()){
    while (x<10){
        /*
        QString descripcion = query.value(0).toString();
        QString fotografia = query.value(1).toString();
        QString estado = query.value(2).toString();
        QString estrellas = query.value(3).toString();
        QString idCasa = query.value(4).toString()*/
        row = i/3;
        col= i%3;

        administrador_tarjeta_gestion *tarjeta = new administrador_tarjeta_gestion;

        i++;
        x++;
        ui->gridLayout->addWidget(tarjeta, row, col);

    }
}

administador_gestionar_usuarios::~administador_gestionar_usuarios()
{
    delete ui;
}
