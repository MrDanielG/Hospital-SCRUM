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
    infoPersona.prepare("SELECT * from persona INNER JOIN usuario ON persona.id_usuario = usuario.id_usuario");
    infoPersona.exec();
    limiparCatalogo();

    int i=0;
    int row = 0;
    int col = 0;

    while(infoPersona.next()){
        QString id_persona = infoPersona.value(0).toString();
        QString nombre_persona = infoPersona.value(1).toString() + " " +  infoPersona.value(2).toString() + " " +  infoPersona.value(3).toString();
        QString img_persona = infoPersona.value(8).toString();
        QString id_usuario = infoPersona.value(10).toString();

        row = i/3;
        col = i%3;

        administrador_tarjeta_gestion *tarjeta = new administrador_tarjeta_gestion(id_usuario, nombre_persona, img_persona);
        i++;
        ui->gridLayout->addWidget(tarjeta, row, col);
    }
}

administador_gestionar_usuarios::~administador_gestionar_usuarios()
{
    delete ui;
}

void administador_gestionar_usuarios::limiparCatalogo()
{
    while ( QLayoutItem* item = ui->gridLayout->takeAt( 0 ) ){
            Q_ASSERT( ! item->layout() ); // otherwise the layout will leak
            delete item->widget();
            delete item;
    }
}
