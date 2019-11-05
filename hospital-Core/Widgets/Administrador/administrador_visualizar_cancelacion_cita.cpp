#include "administrador_visualizar_cancelacion_cita.h"
#include "ui_administrador_visualizar_cancelacion_cita.h"

administrador_visualizar_cancelacion_cita::administrador_visualizar_cancelacion_cita(QString id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administrador_visualizar_cancelacion_cita)
{
    ui->setupUi(this);
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
}

administrador_visualizar_cancelacion_cita::~administrador_visualizar_cancelacion_cita()
{
    delete ui;
}
