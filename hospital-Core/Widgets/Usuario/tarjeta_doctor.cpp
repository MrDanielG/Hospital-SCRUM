#include "tarjeta_doctor.h"
#include "ui_tarjeta_doctor.h"
#include <QDebug>
#include "Widgets/Usuario/info_medico.h"

tarjeta_doctor::tarjeta_doctor(QString idpersona, QString idmedico, QString nombre, QString paterno, QString materno, QString calificacion, QString foto, QString especialidad, QWidget *parent) : QWidget(parent),
    ui(new Ui::tarjeta_doctor){
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

    this->idpersona = idpersona;
    this->idmedico = idmedico;
    this->nombre = nombre;
    this->paterno = paterno;
    this->materno = materno;
    this->calificacion = calificacion;
    this->foto = foto;
    this->especialidad = especialidad;

    ui->estrella1_5->hide();
    ui->estrella1_4->hide();
    ui->estrella1_3->hide();
    ui->estrella1_2->hide();
    ui->estrella1->hide();

}

tarjeta_doctor::~tarjeta_doctor(){
    delete ui;
}

void tarjeta_doctor::insertarDatos(){

    QPixmap imag(this->foto);
    ui->fotografia->setPixmap(imag);
    ui->especialidad->setText(especialidad);
    ui->nombre_doctor->setText(nombre);

    int tamanio = calificacion.toInt();

    if(tamanio == 1){
        ui->estrella1->show();
    }
    if(tamanio == 2){
        ui->estrella1_2->show();
        ui->estrella1_3->show();
    }
    if(tamanio == 3){
        ui->estrella1_2->show();
        ui->estrella1_3->show();
        ui->estrella1_4->show();
    }
    if(tamanio == 4){
        ui->estrella1_2->show();
        ui->estrella1_3->show();
        ui->estrella1_4->show();
        ui->estrella1_5->show();
    }
    if(tamanio == 5){
        ui->estrella1_2->show();
        ui->estrella1_3->show();
        ui->estrella1_4->show();
        ui->estrella1_5->show();
        ui->estrella1->show();
    }

}


void tarjeta_doctor::on_btn_visualizar_clicked(){
    info_medico visualizarInfo(this->idpersona);
    visualizarInfo.exec();
}
