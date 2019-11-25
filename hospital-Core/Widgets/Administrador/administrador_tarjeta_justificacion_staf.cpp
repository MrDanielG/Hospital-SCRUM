#include "administrador_tarjeta_justificacion_staf.h"
#include "ui_administrador_tarjeta_justificacion_staf.h"
#include "Widgets/Administrador/administrador_visualizar_justificacion_staff.h"

administrador_tarjeta_justificacion_staf::administrador_tarjeta_justificacion_staf(QString id, QString descripcion, QString fecha_inicio, QString fecha_fin, QString nombre, QString foto, QString tipo, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::administrador_tarjeta_justificacion_staf)
{
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
    if(!mDatabase.isOpen()){
          qDebug()<<"Error";
           return;
    }else{
            qDebug()<<"abierta";
    }

    this->id = id;
    this->descripcion = descripcion;
    this->fecha_fin = fecha_fin;
    this->fecha_inicio = fecha_inicio;
    this->nombre = nombre;
    this->foto = foto;
    this->tipo = tipo;
}

administrador_tarjeta_justificacion_staf::~administrador_tarjeta_justificacion_staf()
{
    delete ui;
}

void administrador_tarjeta_justificacion_staf::insertarDatos()
{
    QPixmap imag(this->foto);

    ui->foto_staff_lbl->setPixmap(imag);
    ui->nombre_staff_lbl->setText(nombre);
    ui->fecha_fin_lbl->setText(fecha_fin);
    ui->fecha_inicio_lbl->setText(fecha_inicio);
    ui->puesto_lbl->setText(tipo);

}

void administrador_tarjeta_justificacion_staf::on_visualizar_justificacion_pbtn_clicked()
{
    qDebug()<<this->id;
    administrador_visualizar_justificacion_staff dialogo_visualizacion(id, nombre, descripcion);
    dialogo_visualizacion.exec();
}
