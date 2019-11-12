#include "recepcionista_dialogo_gestionar_internado.h"
#include "ui_recepcionista_dialogo_gestionar_internado.h"
#include <QDate>
#include <QMessageBox>
recepcionista_dialogo_gestionar_internado::recepcionista_dialogo_gestionar_internado(QString idPaciente, QString paciente, QString medico, QString habitacion, QDate fecha_fin, QString foto, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::recepcionista_dialogo_gestionar_internado)
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

        this->idPaciente = idPaciente;
        this->paciente = paciente;
        this->medico = medico;
        this->habitacion = habitacion ;
        this->fecha_fin = fecha_fin;
        this->foto = foto;
}

recepcionista_dialogo_gestionar_internado::~recepcionista_dialogo_gestionar_internado()
{
    delete ui;
}

void recepcionista_dialogo_gestionar_internado::insertarDatos()
{
    QPixmap imag(this->foto);

    int restantes = 0;
    QString diasRestantes;
    if(fecha_fin.toString() == ""){
        diasRestantes = "-";
    }
    else {
        QDate inicio = inicio.currentDate();
        restantes = inicio.daysTo(fecha_fin);
    }

    ui->lbl_foto_paciente->setPixmap(imag);
    ui->lbl_nombre_paciente->setText(paciente);
    ui->lbl_medico->setText(medico);
    ui->restantes_lineEdit->setValue(restantes);
    ui->habitacion_lineEdit->setValue(habitacion.toInt());
}

void recepcionista_dialogo_gestionar_internado::on_btn_cancelar_internado_clicked()
{
    QMessageBox messageBox(QMessageBox::Question,tr("Critical Error"), tr("Estás seguro de dar de baja a éste internado?"), QMessageBox::Yes | QMessageBox::No);

    messageBox.setButtonText(QMessageBox::Yes, tr("Sí"));
    messageBox.setButtonText(QMessageBox::No, tr("No"));

    if (messageBox.exec() == QMessageBox::Yes){
        QSqlQuery query(mDatabase);
        QString sql = "delete from internados where id_paciente = "+idPaciente+";";
        query.prepare(sql);
        query.exec();
    }
    this->close();
}

void recepcionista_dialogo_gestionar_internado::on_btn_agregar_internado_2_clicked()
{
    QString habitacion = ui->habitacion_lineEdit->text();
    int restantes = ui->restantes_lineEdit->text().toInt();
    QDate fin = (fin.currentDate().addDays(restantes));
    QString fechafin = QString::number(fin.year())+"-"+QString::number(fin.month())+"-"+QString::number(fin.day());
    qDebug()<<"Fecha fin = "+fechafin;

    QMessageBox messageBox(QMessageBox::Question,tr("Critical Error"), tr("Estás seguro de guardar las modificaciones?"), QMessageBox::Yes | QMessageBox::No);

    messageBox.setButtonText(QMessageBox::Yes, tr("Sí"));
    messageBox.setButtonText(QMessageBox::No, tr("No"));

    if (messageBox.exec() == QMessageBox::Yes){
        QSqlQuery query(mDatabase);
        QString sql = "update internados set fecha_fin = '"+fechafin+"', habitacion = "+habitacion+" where id_paciente = "+idPaciente+";";
        qDebug()<<sql;
        query.prepare(sql);
        query.exec();
    }

    this->close();
}
