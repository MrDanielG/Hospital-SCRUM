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
    QDate fecha = fecha.currentDate();
    ui->dateEdit->setDate(fecha);
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

    QString currentFecha = QString::number(fecha.year())+"-"+QString::number(fecha.month())+"-"+QString::number(fecha.day());

    query.prepare("select * from tarjetaCitaHorario where estado = 1 and fecha = '"+currentFecha+"';");
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
        QString idCita = query.value(8).toString();

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

void medico_horario::limiparCatalogo()
{
    while (QLayoutItem *item = ui->gridLayout_horario->takeAt(0))
    {
        Q_ASSERT(!item->layout()); // otherwise the layout will leak
        delete item->widget();
        delete item;
    }
}

void medico_horario::setIdUsuario(QString id)
{
    limiparCatalogo();

    this->idUsuario = id;
    QDate fecha = fecha.currentDate();
    QSqlQuery query(mDatabase);
    QString currentFecha = QString::number(fecha.year())+"-"+QString::number(fecha.month())+"-"+QString::number(fecha.day());

    QString prueba = "select id_persona from persona where id_usuario = '"+this->idUsuario+"';";
    qDebug()<< "Qery1: "+prueba;
    query.exec(prueba);
    QString id_persona;
    while (query.next()) {
        id_persona = query.value(0).toString();
    }

    prueba = "select id_empleado from empleado where id_persona = "+id_persona+";";
    qDebug()<< "Qery2: "+prueba;
    query.exec(prueba);
    QString id_empleado;
    while (query.next()) {
        id_empleado = query.value(0).toString();
    }

    prueba = "select id_medico from medico where id_empleado = "+id_empleado+";";
    qDebug()<< "Qery3: "+prueba;
    query.exec(prueba);
    QString id_medico;
    while (query.next()) {
        id_medico = query.value(0).toString();
    }
    this->medico = id_medico;

    prueba = "select * from tarjetaCitaHorario where estado = 1 and fecha = '"+currentFecha+"' and Medico = "+id_medico+";";
    qDebug()<< "Qery4: "+prueba;
    query.exec(prueba);

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
        QString idCita = query.value(8).toString();

         row = i/4;
         col= i%4;

         medico_tarjeta_horario *tarjeta = new medico_tarjeta_horario(nombre, paterno, materno, morivo, hInicio, hFin, foto,idCita);
         tarjeta->insertarDatos();

         i++;
         ui->gridLayout_horario->addWidget(tarjeta, row, col);
    }
}

void medico_horario::on_pushButton_clicked()
{
    QSqlQuery query;
    QString sql;
    QString fecha = QString::number(ui->dateEdit->date().year())+"-"+QString::number(ui->dateEdit->date().month())+"-"+QString::number(ui->dateEdit->date().day());

    limiparCatalogo();

    sql = "select * from tarjetaCitaHorario where estado = 1 and fecha = '"+fecha+"' and Medico = "+medico+";";
    qDebug()<<"QuerBusqueda: "+sql;
    query.exec(sql);

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

         medico_tarjeta_horario *tarjeta = new medico_tarjeta_horario(nombre, paterno, materno, morivo, hInicio, hFin, foto, cita);
         tarjeta->insertarDatos();

         i++;
         ui->gridLayout_horario->addWidget(tarjeta, row, col);
    }
}
