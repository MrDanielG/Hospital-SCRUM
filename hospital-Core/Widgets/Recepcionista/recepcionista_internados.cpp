#include "recepcionista_internados.h"
#include "ui_recepcionista_internados.h"
#include "Widgets/Recepcionista/recepcionista_tarjeta_internados.h"
#include "Widgets/Recepcionista/recepcionista_tarjeta_medicos_internado.h"
#include "Widgets/Recepcionista/recepcionista_tarjeta_pacientes_internados.h"
#include <QDebug>
#include <QDate>
#include <QMessageBox>

recepcionista_internados::recepcionista_internados(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::recepcionista_internados)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
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
     limiparCatalogo();
     actualizarCatalogo();
}

recepcionista_internados::~recepcionista_internados()
{
    delete ui;
}

void recepcionista_internados::limiparCatalogo()
{
    while (QLayoutItem *item = ui->gridLayout_internados->takeAt(0))
    {
        Q_ASSERT(!item->layout());
        delete item->widget();
        delete item;
    }
}

void recepcionista_internados::actualizarCatalogo()
{
    QSqlQuery query(mDatabase);
    query.prepare("select * from tarjetaInternados;");
    query.exec();

    int i=0;
    int row = 0;
    int col = 0;

    while (query.next()) {
        QString idPaciente = query.value(0).toString();
        QString nPaciente = query.value(1).toString();
        QString pPaciente = query.value(2).toString();
        QString mPaciente = query.value(3).toString();
        QString medico = query.value(4).toString();
        QString habitacion = query.value(5).toString();
        QDate fin = query.value(6).toDate();
        QString foto = query.value(7).toString();

        QString paciente = nPaciente+" "+pPaciente+" "+mPaciente;

         row = i/4;
         col= i%4;

         recepcionista_tarjeta_internados *tarjeta = new recepcionista_tarjeta_internados(idPaciente, paciente, medico, habitacion, fin, foto);
         tarjeta->insertarDatos();

         i++;
         ui->gridLayout_internados->addWidget(tarjeta, row, col);
    }
}

void recepcionista_internados::on_btn_agregar_internado_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
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


         row = i/3;
         col= i%3;

         recepcionista_tarjeta_medicos_internado *tarjeta = new recepcionista_tarjeta_medicos_internado (idpersona, idmedico, nombre, paterno, materno, calificacion, foto, especialidad);
         tarjeta->insertarDatos();
         i++;
         ui->gridLayout_medicos->addWidget(tarjeta, row, col);

    }

    QSqlQuery query2(mDatabase);
    query2.prepare("select * from tarjetaPacientes;");
    query2.exec();

    while(query2.next()){
         QString id = query2.value(0).toString();
         QString nombre = query2.value(1).toString();
         QString paterno = query2.value(2).toString();
         QString materno = query2.value(3).toString();
         QString foto = query2.value(4).toString();
         QString curp = query2.value(5).toString();

         row = i/3;
         col= i%3;

         recepcionista_tarjeta_pacientes_internados *tarjeta = new recepcionista_tarjeta_pacientes_internados(id, nombre, paterno, materno, foto, curp);
         tarjeta->insertarDatos();
         i++;
         ui->gridLayout_pacientes->addWidget(tarjeta, row, col);

    }

}

void recepcionista_internados::on_btn_cancelar_internado_clicked()
{
    ui->paciente_linEdit->setText("");
    ui->medico_linEdit->setText("");
    ui->fin_linEdit->setText("");
    ui->habitacion_linEdit->setText("");
    ui->stackedWidget->setCurrentIndex(0);
}

void recepcionista_internados::on_btn_agregar_internado_2_clicked()
{
    QDate date = date.currentDate();
    QString fecha_inicio = QString::number(date.year())+"-"+QString::number(date.month())+"-"+QString::number(date.day());
    QString fecha_fin = ui->fin_linEdit->text();
    QString id_paciente = ui->paciente_linEdit->text();
    QString id_medico = ui->medico_linEdit->text();
    QString habitacion = ui->habitacion_linEdit->text();

    if(id_paciente == "" || id_medico == "" || habitacion == ""){
        QMessageBox::warning(this,"Datos incompletos", "Por favor llena todos los campos obligatorios marcados con un *");
    }
    else if(fecha_fin == ""){
        QMessageBox messageBox(QMessageBox::Question,tr("Critical Error"), tr("Estás seguro de registrar éste internado"), QMessageBox::Yes | QMessageBox::No);

        messageBox.setButtonText(QMessageBox::Yes, tr("Sí"));
        messageBox.setButtonText(QMessageBox::No, tr("No"));

        if (messageBox.exec() == QMessageBox::Yes){
            QSqlQuery query(mDatabase);
            QString sql = "insert into internados(fecha_inicio, id_paciente, id_medico, habitacion) values('"+fecha_inicio+"', "+id_paciente+", "+id_medico+", "+habitacion+");";
            qDebug()<<sql;
            query.prepare(sql);
            query.exec();
            QMessageBox::information(this, "Agregado", "El internado ha sido agregado correctamente");
            limiparCatalogo();
            actualizarCatalogo();
            ui->paciente_linEdit->setText("");
            ui->medico_linEdit->setText("");
            ui->fin_linEdit->setText("");
            ui->habitacion_linEdit->setText("");
            ui->stackedWidget->setCurrentIndex(0);
        }
    }
    else {
        QMessageBox messageBox(QMessageBox::Question,tr("Critical Error"), tr("Estás seguro de registrar éste internado"), QMessageBox::Yes | QMessageBox::No);

        messageBox.setButtonText(QMessageBox::Yes, tr("Sí"));
        messageBox.setButtonText(QMessageBox::No, tr("No"));

        if (messageBox.exec() == QMessageBox::Yes){
            QSqlQuery query(mDatabase);
            QString sql = "insert into internados(fecha_inicio, fecha_fin, id_paciente, id_medico, habitacion) values('"+fecha_inicio+"', '"+fecha_fin+"', "+id_paciente+", "+id_medico+", "+habitacion+");";
            qDebug()<<sql;
            query.prepare(sql);
            query.exec();
            QMessageBox::information(this, "Agregado", "El internado ha sido agregado correctamente");
            limiparCatalogo();
            actualizarCatalogo();
            ui->paciente_linEdit->setText("");
            ui->medico_linEdit->setText("");
            ui->fin_linEdit->setText("");
            ui->habitacion_linEdit->setText("");
            ui->stackedWidget->setCurrentIndex(0);
        }
    }

}
