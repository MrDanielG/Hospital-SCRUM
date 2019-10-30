#include "info_medico.h"
#include "ui_info_medico.h"

info_medico::info_medico(QString id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::info_medico)
{
    ui->setupUi(this);
    mDatabase = QSqlDatabase::database("Connection");
    if(!mDatabase.isOpen()){
        qDebug() << "ERROR";
    }else{
        qDebug() << "base de datos sigue conectada en INICIAR SESION";
    }
    this->idinfo = id;


    if(!mDatabase.isOpen()){
        qDebug() << "ERROR";
    }else{
        qDebug() << "base de datos sigue conectada en INICIAR SESION";
    }

    QSqlQuery query(mDatabase);
    query.prepare("select id_persona, nombre, paterno, materno, fNacimiento, correo, foto from persona where id_persona = "+idinfo);
    query.exec();

    while(query.next()){
         QString idmedico = query.value(0).toString();
         QString nombre = query.value(1).toString();
         QString paterno = query.value(2).toString();
         QString materno = query.value(3).toString();
         QString edad = query.value(4).toString();
         QString correo = query.value(5).toString();
         QString foto = query.value(5).toString();
         insertarDatos(nombre, paterno, materno, edad, correo, foto);
    }


}

info_medico::~info_medico(){

    delete ui;
}

void info_medico::insertarDatos(QString nombre, QString paterno, QString materno, QString edad, QString correo, QString foto){
    QPixmap img(foto);
    ui->foto_medico->setPixmap(img.scaled(241,201, Qt::IgnoreAspectRatio));
}
