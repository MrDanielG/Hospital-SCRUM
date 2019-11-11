#include "recepcionista_citas.h"
#include "ui_recepcionista_citas.h"

recepcionista_citas::recepcionista_citas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::recepcionista_citas)
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
        qDebug() << "ERROR con Base de Datos, esto es: CREAR CITAS";
        return;
    }else{
        qDebug() << "Base de datos continua abierta, esto es: CREAR CITAS";
    }

    QSqlQuery MostrarDatos(mDatabase);

    MostrarDatos.prepare("select cita.fecha, cita.hora_inicio, persona.nombre, persona.paterno "
                         "From persona INNER JOIN empleado "
                         "ON persona.id_persona = empleado.id_persona "
                         "INNER JOIN medico "
                         "ON empleado.id_empleado = medico.id_empleado "
                         "INNER JOIN cita_medica as cita "
                         "ON medico.id_medico = cita.id_medico "
                         "where medico.id_medico = 23");
    MostrarDatos.exec();
    int i=0;
    int row = 0;
    int col = 0;

    while (MostrarDatos.next()){
        QString fecha = MostrarDatos.value(0).toString();
        QString hora = MostrarDatos.value(1).toString();
        QString medico = MostrarDatos.value(2).toString();
        QString medicopaterno = MostrarDatos.value(3).toString();
        row = i/2;
        col= i%2;

        recepcion_tarjeta_citas *tarjeta = new recepcion_tarjeta_citas();
        tarjeta->insertarDatos(fecha, hora, medico, medicopaterno);
        i++;
        ui->gridLayout->addWidget(tarjeta, row, col);
    }


}

recepcionista_citas::~recepcionista_citas()
{
    delete ui;
}

void recepcionista_citas::insertarDatos()
{

}


