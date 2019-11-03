#include "info_servicios.h"
#include "ui_info_servicios.h"

info_servicios::info_servicios(QString idinfo, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::info_servicios)
{
    ui->setupUi(this);

    this->idinfo = idinfo;
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

    int id = idinfo.toInt();
    qDebug()<<id<< "Este es el id" <<" Este es el otro"<< idinfo;

    QSqlQuery query(mDatabase);

    query.prepare("select nombre, descripcion, imagen from info where id_info = "+ idinfo);
    query.exec();


    while (query.next()){
        QString nombre = query.value(0).toString();
        QString descripcion = query.value(1).toString();
        QString imagen = query.value(2).toString();
        insertarDatos(nombre, descripcion, imagen);
    }

}

info_servicios::~info_servicios(){
    delete ui;
}

void info_servicios::insertarDatos(QString nombre, QString descripcion, QString imagen){
    QPixmap imag(imagen);
    ui->img_servicio->setPixmap(imag.scaled(161,131, Qt::IgnoreAspectRatio));
    ui->text_descripcion_servicio->setPlainText(descripcion);
    ui->nombre_servicio->setText(nombre);
}
