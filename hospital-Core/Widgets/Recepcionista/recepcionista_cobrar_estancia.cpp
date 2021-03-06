#include "recepcionista_cobrar_estancia.h"
#include "ui_recepcionista_cobrar_estancia.h"
#include "Widgets/Recepcionista/recepcionista_tarjeta_cobro.h"
#include "Clases/pdf_cobro.h"
#include "QDebug"
#include "QDate"
recepcionista_cobrar_estancia::recepcionista_cobrar_estancia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::recepcionista_cobrar_estancia)
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
            qDebug() << "ERROR  en RECEPCIONISTA COBRAR ESTANCIA";
        }else{
            qDebug() << "Base de datos sigue conectada en RECEPCIONISTA COBRAR ESTANCIA";
        }

    inicializarCatalogo();
}

recepcionista_cobrar_estancia::~recepcionista_cobrar_estancia()
{
    delete ui;
}

void recepcionista_cobrar_estancia::inicializarCatalogo()
{
    QSqlQuery query(mDatabase);
    query.prepare("SELECT id_internado, fecha_inicio, habitacion, p2.nombre as nombreInt, p2.paterno as paternoInt, p2.materno as maternoInt, p2.foto as fotoInt, p5.nombre as nombreMed, p5.paterno as paternoMed, p5.materno as maternoMed FROM internados as t1 INNER JOIN paciente as p1 ON t1.id_paciente = p1.id_paciente INNER JOIN persona as p2 ON p2.id_persona = p1.id_persona INNER JOIN medico as p3 ON t1.id_medico = p3.id_medico INNER JOIN empleado as p4 ON p4.id_empleado = p3.id_empleado INNER JOIN persona as p5 ON p5.id_persona = p4.id_persona");
    query.exec();

    int i=0;
    int row = 0;
    int col = 0;

    while (query.next()) {
        QString nombre = query.value("nombreInt").toString() + " " +query.value("paternoInt").toString();
        QString fecha = query.value("fecha_inicio").toString();
        QString habitacion = query.value("habitacion").toString();
        QString foto = query.value("fotoInt").toString();
        QString idInternado = query.value("id_internado").toString();
         row = i/1;
         col= i%1;

         recepcionista_tarjeta_cobro *tarjeta = new recepcionista_tarjeta_cobro(idInternado, nombre, habitacion, foto, fecha, this);

         i++;
         ui->gridLayout_horario_2->addWidget(tarjeta, row, col);
    }
}

void recepcionista_cobrar_estancia::inicializarRececta(QString _idInterno)
{
    this->idInternado = _idInterno;

    QSqlQuery query(mDatabase);
    query.prepare("SELECT fecha_inicio, habitacion, p2.nombre as nombreInt, p2.paterno as paternoInt, p2.materno as maternoInt, p2.foto as fotoInt, p5.nombre as nombreMed, p5.paterno as paternoMed, p5.materno as maternoMed FROM internados as t1 INNER JOIN paciente as p1 ON t1.id_paciente = p1.id_paciente INNER JOIN persona as p2 ON p2.id_persona = p1.id_persona INNER JOIN medico as p3 ON t1.id_medico = p3.id_medico INNER JOIN empleado as p4 ON p4.id_empleado = p3.id_empleado INNER JOIN persona as p5 ON p5.id_persona = p4.id_persona WHERE t1.id_internado = '"+_idInterno+"'");
    query.exec();
    query.next();

    QString nombre = query.value("nombreInt").toString() + " " +query.value("paternoInt").toString() + " " +query.value("maternoInt").toString();
    QString fecha = query.value("fecha_inicio").toString();
    QString habitacion = query.value("habitacion").toString();
    QString nombreMed = query.value("nombreMed").toString() + " " +query.value("paternoMed").toString() + " " +query.value("maternoMed").toString();

    QDate fechaChida = QDate::fromString(fecha, "yyyy-MM-dd");
    QDate fechaActual = QDate::currentDate();

    int dt = fechaChida.daysTo(fechaActual);
    QString diasTotales = QString::number(dt);

    ui->nombreMedico->setText(nombreMed);
    ui->nombrePaciente->setText(nombre);
    ui->numHabitacion->setText(habitacion);
    ui->numDias->setText(diasTotales);
}

void recepcionista_cobrar_estancia::on_spinBoxCosto_valueChanged(int arg1)
{
    int _diasTotales = ui->numDias->text().toInt();
    this->diasTotales = QString::number(_diasTotales);
    int total = arg1 * _diasTotales;
    QString totalString = QString::number(total);
    this->precioTotal = totalString;
    ui->totalCobro->setText(totalString + " pesos mexicanos");
}

void recepcionista_cobrar_estancia::on_btnGenerarTicket_clicked()
{
    QSqlQuery query(mDatabase);
    query.prepare("SELECT fecha_inicio, habitacion, p2.nombre as nombreInt, p2.paterno as paternoInt, p2.materno as maternoInt, p2.foto as fotoInt, p5.nombre as nombreMed, p5.paterno as paternoMed, p5.materno as maternoMed FROM internados as t1 INNER JOIN paciente as p1 ON t1.id_paciente = p1.id_paciente INNER JOIN persona as p2 ON p2.id_persona = p1.id_persona INNER JOIN medico as p3 ON t1.id_medico = p3.id_medico INNER JOIN empleado as p4 ON p4.id_empleado = p3.id_empleado INNER JOIN persona as p5 ON p5.id_persona = p4.id_persona WHERE t1.id_internado = '"+this->idInternado+"'");
    query.exec();
    query.next();

    QString nombre = query.value("nombreInt").toString() + " " +query.value("paternoInt").toString() + " " +query.value("maternoInt").toString();
    QString fecha = query.value("fecha_inicio").toString();
    QString habitacion = query.value("habitacion").toString();
    QString nombreMed = query.value("nombreMed").toString() + " " +query.value("paternoMed").toString() + " " +query.value("maternoMed").toString();

    pdf_cobro ticket(nombre, nombreMed, fecha, this->diasTotales, this->precioTotal);
}
