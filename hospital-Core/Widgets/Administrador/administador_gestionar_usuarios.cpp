#include "administador_gestionar_usuarios.h"
#include "ui_administador_gestionar_usuarios.h"
#include "Widgets/Administrador/administrador_tarjeta_gestion.h"
#include "QMessageBox"
#include "QDebug"
#include "QSqlQuery"
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

    QSqlQuery infoPersona(mDatabase);
    //infoPersona.prepare();
    //infoPersona.exec();

    int i=0;
    int row = 0;
    int col = 0;

    for(int j=0; j<4; j++){
        row = i/3;
        col = i%3;

        administrador_tarjeta_gestion *tarjeta = new administrador_tarjeta_gestion;
        i++;
        ui->gridLayout->addWidget(tarjeta, row, col);
    }
}

administador_gestionar_usuarios::~administador_gestionar_usuarios()
{
    delete ui;
}
