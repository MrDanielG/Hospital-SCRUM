#include "medico_horario.h"
#include "ui_medico_horario.h"
#include "Widgets/Medico/medico_tarjeta_horario.h"
#include <QDebug>
#include <QSqlError>

medico_horario::medico_horario(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::medico_horario)
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
            qDebug() << "ERROR";
        }else{
            qDebug() << "base de datos sigue conectada en INICIAR SESION";
        }

    QSqlQuery query(mDatabase);
    query.prepare("select * from tarjetaCitaHorario");
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
        QString idCita = query.value(7).toString();

         row = i/4;
         col= i%4;

         medico_tarjeta_horario *tarjeta = new medico_tarjeta_horario(nombre, paterno, materno, morivo, hInicio, hFin, foto,idCita);
         tarjeta->insertarDatos();

         i++;
         ui->gridLayout_horario->addWidget(tarjeta, row, col);
    }


}
medico_horario::~medico_horario()
{
    delete ui;
}
