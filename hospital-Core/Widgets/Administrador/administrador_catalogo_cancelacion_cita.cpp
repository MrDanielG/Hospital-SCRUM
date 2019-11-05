#include "administrador_catalogo_cancelacion_cita.h"
#include "ui_administrador_catalogo_cancelacion_cita.h"
#include "Widgets/Administrador/administrador_tarjeta_cancelacion_cita.h"
#include <QDebug>

administrador_catalogo_cancelacion_cita::administrador_catalogo_cancelacion_cita(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::administrador_catalogo_cancelacion_cita)
{
    ui->setupUi(this);
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
            qDebug() << "ERROR";
        }else{
            qDebug() << "base de datos sigue conectada en INICIAR SESION";
        }

    QSqlQuery query(mDatabase);
    query.prepare("select * from tarjetaCitaHorario where estado = 1");
    query.exec();

    int i=0;
    int row = 0;
    int col = 0;

    while (query.next()) {
        QString nombre = query.value(0).toString();
        QString paterno = query.value(1).toString();
        QString materno = query.value(2).toString();
        QString morivo = query.value(3).toString();
        QString hInicio = query.value(4).toString();
        QString hFin = query.value(5).toString();
        QString foto = query.value(6).toString();
        QString cita = query.value(8).toString();

         row = i/4;
         col= i%4;

         administrador_tarjeta_cancelacion_cita *tarjeta = new administrador_tarjeta_cancelacion_cita(nombre, paterno, materno, morivo, hInicio, hFin, foto, cita);
         tarjeta->insertarDatos();

         i++;
         ui->gridLayout_horario->addWidget(tarjeta, row, col);
    }
}

administrador_catalogo_cancelacion_cita::~administrador_catalogo_cancelacion_cita()
{
    delete ui;
}
