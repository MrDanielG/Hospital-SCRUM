#include "medico_solicitudes.h"
#include "ui_medico_solicitudes.h"
#include "Widgets/Medico/medico_tarjeta_citarechazada.h"

medico_solicitudes::medico_solicitudes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::medico_solicitudes)
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
        qDebug() << "base de datos sigue conectada en Medico_Solicitudes";
    }

}

medico_solicitudes::~medico_solicitudes()
{
    delete ui;
}

void medico_solicitudes::setIdMedico(QString idMedico)
{
    this->idMedico=idMedico;
}

void medico_solicitudes::limpiarCatalogo()
{
    while (QLayoutItem *item = ui->gridLayout->takeAt(0))
    {
        Q_ASSERT(!item->layout()); // otherwise the layout will leak
        delete item->widget();
        delete item;
    }
}

void medico_solicitudes::on_btn_solicitudesEspera_clicked()
{
    QSqlQuery query(mDatabase);
    query.prepare("select * from tarjetaSolicitudesCitaRechazadas where id_medico='"+this->idMedico+"' and estado=1");
    query.exec();

    limpiarCatalogo();

    int i = 0;
    int row = 0;
    int col = 0;

    while(query.next())
    {
        QString nombre = query.value(0).toString();
        QString paterno = query.value(1).toString();
        QString materno = query.value(2).toString();
        QString morivo = query.value(3).toString();
        QString hInicio = query.value(4).toString();
        QString hFin = query.value(5).toString();
        QString foto = query.value(7).toString();

        row = i / 4;
        col = i % 4;
        medico_tarjeta_CitaRechazada *tarjeta= new medico_tarjeta_CitaRechazada(nombre, paterno, materno, morivo, hInicio, hFin, foto);
        tarjeta->insertarDatos();

        i++;
        ui->gridLayout->addWidget(tarjeta, row, col);
    }
}

void medico_solicitudes::on_btn_solicitudesRechazadas_clicked()
{

    QSqlQuery query(mDatabase);
    query.prepare("select * from tarjetaSolicitudesCitaRechazadas where id_medico='"+this->idMedico+"' and estado=3");
    query.exec();

    limpiarCatalogo();

    int i = 0;
    int row = 0;
    int col = 0;

    while(query.next())
    {
        QString nombre = query.value(0).toString();
        QString paterno = query.value(1).toString();
        QString materno = query.value(2).toString();
        QString morivo = query.value(3).toString();
        QString hInicio = query.value(4).toString();
        QString hFin = query.value(5).toString();
        QString foto = query.value(7).toString();

        row = i / 3;
        col = i % 3;
        medico_tarjeta_CitaRechazada *tarjeta= new medico_tarjeta_CitaRechazada(nombre, paterno, materno, morivo, hInicio, hFin, foto);
        tarjeta->insertarDatos();

        i++;
        ui->gridLayout->addWidget(tarjeta, row, col);
    }
}

void medico_solicitudes::on_btn_solicitudesAprobadas_clicked()
{
    QSqlQuery query(mDatabase);
    query.prepare("select * from tarjetaSolicitudesCitaRechazadas where id_medico='"+this->idMedico+"' and estado=2");
    query.exec();

    limpiarCatalogo();

    int i = 0;
    int row = 0;
    int col = 0;

    while(query.next())
    {
        QString nombre = query.value(0).toString();
        QString paterno = query.value(1).toString();
        QString materno = query.value(2).toString();
        QString morivo = query.value(3).toString();
        QString hInicio = query.value(4).toString();
        QString hFin = query.value(5).toString();
        QString foto = query.value(7).toString();

        row = i / 4;
        col = i % 4;
        medico_tarjeta_CitaRechazada *tarjeta= new medico_tarjeta_CitaRechazada(nombre, paterno, materno, morivo, hInicio, hFin, foto);
        tarjeta->insertarDatos();

        i++;
        ui->gridLayout->addWidget(tarjeta, row, col);
    }
}

void medico_solicitudes::inicializar()
{
    on_btn_solicitudesEspera_clicked();
}
