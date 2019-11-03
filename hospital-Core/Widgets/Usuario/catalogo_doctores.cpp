#include "catalogo_doctores.h"
#include "ui_catalogo_doctores.h"
#include <QSqlQuery>
#include "Widgets/Usuario/tarjeta_doctor.h"
#include "Clases/doctor.h"

catalogo_doctores::catalogo_doctores(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::catalogo_doctores)
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
    query.prepare("select * from tarjetaMedicos");
    query.exec();

    int i=0;
    int row = 0;
    int col = 0;

    while(query.next()){
         QString idpersona = query.value(0).toString();
         QString idmedico = query.value(1).toString();
         QString nombre = query.value(2).toString();
         QString paterno = query.value(3).toString();
         QString materno = query.value(4).toString();
         QString calificacion = query.value(5).toString();
         QString foto = query.value(6).toString();
         QString especialidad = "cirujano";


         row = i/4;
         col= i%4;

         tarjeta_doctor *tarjeta = new tarjeta_doctor(idpersona, idmedico, nombre, paterno, materno, calificacion, foto, especialidad);
         tarjeta->insertarDatos();
         i++;
         ui->gridLayout->addWidget(tarjeta, row, col);

    }



}

catalogo_doctores::~catalogo_doctores()
{
    delete ui;
}
