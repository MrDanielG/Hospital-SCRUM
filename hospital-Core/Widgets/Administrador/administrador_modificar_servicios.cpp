#include "administrador_modificar_servicios.h"
#include "ui_administrador_modificar_servicios.h"
#include "QDebug"
administrador_modificar_servicios::administrador_modificar_servicios(QString id_servicio, QString nombre, QString info, QString foto, QWidget *parent) :
    QDialog(parent),
     ui(new Ui::administrador_modificar_servicios)
{
    ui->setupUi(this);
    mDatabase = QSqlDatabase::database("Connection");
    if (!mDatabase.isOpen())
    {
        qDebug() << "ERROR con Base de Datos, esto es: MODIFICAR USUARIOS";
        return;
    }
    else
    {
        qDebug() << "Base de datos continua abierta, esto es: MODIFICAR USUARIOS";
    }

    //Se agrega la info a la UI
    ui->nombre_servicio->setText(nombre);
    ui->info_servicio->setPlainText(info);
    QPixmap img(foto);
    ui->img->setPixmap(img);
}

administrador_modificar_servicios::~administrador_modificar_servicios()
{
    delete ui;
}
