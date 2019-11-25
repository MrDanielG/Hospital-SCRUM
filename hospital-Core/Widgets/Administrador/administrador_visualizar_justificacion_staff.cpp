#include "administrador_visualizar_justificacion_staff.h"
#include "ui_administrador_visualizar_justificacion_staff.h"

administrador_visualizar_justificacion_staff::administrador_visualizar_justificacion_staff(QString id, QString nombre, QString motivo, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administrador_visualizar_justificacion_staff)
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
    if (!mDatabase.isOpen()){
        qDebug() << "ERROR";
    }else{
        qDebug() << "base de datos sigue conectada en VISUALIZAR CANCELACION";
    }

    this->id = id;
    this->nombre = nombre;
    this->motivo = motivo;

    ui->nombre->setText(nombre);
    ui->motivo->setPlainText(motivo);
    ui->id->setText(id);
}

administrador_visualizar_justificacion_staff::~administrador_visualizar_justificacion_staff()
{
    delete ui;
}

void administrador_visualizar_justificacion_staff::insertarDatos()
{
//    ui->nombre->setText(nombre);
//    ui->motivo->setPlainText(motivo);
//    ui->id->setText(id);
}
