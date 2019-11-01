#include "tarjeta_servicios.h"
#include "ui_tarjeta_servicios.h"
#include "Widgets/Usuario/info_servicios.h"
#include <QDebug>

Tarjeta_Servicios::Tarjeta_Servicios(QString id, QString foto, QString nombre, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tarjeta_Servicios){
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
    if (!mDatabase.isOpen()){
        qDebug() << "ERROR";
    }else{
        qDebug() << "base de datos sigue conectada en INICIAR SESION";
    }

    this->id = id;
    this->foto = foto;
    this->nombre = nombre;

}

Tarjeta_Servicios::~Tarjeta_Servicios()
{
    delete ui;
}

void Tarjeta_Servicios::insertarDatos(){
    QPixmap imag(this->foto);
    ui->img_servicios->setPixmap(imag);
    ui->nombre_servicio->setText(this->nombre);

}

void Tarjeta_Servicios::on_btn_visualizar_servicio_clicked(){
    info_servicios visualizarInfo(this->id);
    visualizarInfo.exec();

}
