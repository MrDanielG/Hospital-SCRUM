#include "administrador_horarios_medicos.h"
#include "ui_administrador_horarios_medicos.h"
#include "Widgets/Medico/medico_tarjeta_horario.h"
#include <QDebug>
administrador_horarios_medicos::administrador_horarios_medicos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::administrador_horarios_medicos)
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
            qDebug() << "ERROR en ADMINISTRADOR HORARIOS MEDICOS";
        }else{
            qDebug() << "base de datos sigue conectada en ADMINISTRADOR HORARIOS MEDICOS";
        }

     QSqlQuery query(mDatabase);
     query.prepare("SELECT id_medico FROM medico");
     query.exec();

     int i = 0;
     while (query.next()){
         i++;
         QString idMedico = query.value(0).toString();
         ui->comboBox_ID->insertItem(i,idMedico);
     }

     ui->dateEdit->setDate(fecha);

     inicializarCatalogo();
}

administrador_horarios_medicos::~administrador_horarios_medicos()
{
    delete ui;
}

void administrador_horarios_medicos::limiparCatalogo()
{
    while (QLayoutItem *item = ui->gridLayout_horario->takeAt(0))
    {
        Q_ASSERT(!item->layout()); // otherwise the layout will leak
        delete item->widget();
        delete item;
    }
}

void administrador_horarios_medicos::inicializarCatalogo()
{
    qDebug()<<"Inicializando Catalogo"<<ui->comboBox_ID->currentText();
    QDate fecha = ui->dateEdit->date();
    QString currentFecha = QString::number(fecha.year())+"-"+QString::number(fecha.month())+"-"+QString::number(fecha.day());
    limiparCatalogo();
    QSqlQuery query(mDatabase);
    query.prepare("SELECT * FROM tarjetaCitaHorario WHERE estado = 1 AND fecha = '"+currentFecha+"' AND Medico = "+ui->comboBox_ID->currentText());
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

void administrador_horarios_medicos::on_comboBox_ID_currentIndexChanged(int index)
{
    QSqlQuery query(mDatabase);
    query.prepare("SELECT nombre, paterno, materno FROM medico "
                  "INNER JOIN empleado ON medico.id_empleado = empleado.id_empleado "
                  "INNER JOIN persona ON empleado.id_persona = persona.id_persona "
                  "WHERE id_medico = "+ui->comboBox_ID->currentText());
    query.exec();
    query.next();
    QString nombreMedico = query.value("nombre").toString() + " " +query.value("paterno").toString() + " " +query.value("materno").toString();
    ui->label_nombre_medico->setText(nombreMedico);
    inicializarCatalogo();
}

void administrador_horarios_medicos::on_dateEdit_userDateChanged(const QDate &date)
{
    inicializarCatalogo();
}
