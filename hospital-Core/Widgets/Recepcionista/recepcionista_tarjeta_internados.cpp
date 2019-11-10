#include "recepcionista_tarjeta_internados.h"
#include "ui_recepcionista_tarjeta_internados.h"
#include "Widgets/Recepcionista/recepcionista_dialogo_gestionar_internado.h"
recepcionista_tarjeta_internados::recepcionista_tarjeta_internados(QString id_paciente, QString paciente, QString medico, QString habitacion, QDate fecha_fin, QString foto, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::recepcionista_tarjeta_internados)
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
          qDebug()<<"Error";
           return;
    }else{
            qDebug()<<"abierta";
    }

    this->idPaciente = id_paciente;
    this->paciente = paciente;
    this->medico = medico;
    this->habitacion = habitacion ;
    this->fecha_fin = fecha_fin;
    this->foto = foto;
}

recepcionista_tarjeta_internados::~recepcionista_tarjeta_internados()
{
    delete ui;
}

void recepcionista_tarjeta_internados::insertarDatos()
{
    QPixmap imag(this->foto);

    ui->lbl_foto_paciente->setPixmap(imag);
    ui->lbl_nombre_paciente->setText(paciente);
    ui->lbl_medico->setText(medico);
    ui->lbl_habitacion->setText(habitacion);
    ui->lbl_dias_restantes->setText(fecha_fin.toString());
}

void recepcionista_tarjeta_internados::on_btn_gestionar_internado_clicked()
{
    recepcionista_dialogo_gestionar_internado dialogo(idPaciente, paciente, medico, habitacion, fecha_fin, foto);
    dialogo.insertarDatos();
    dialogo.exec();
}