#include "administrador_visualizar_cancelacion_cita.h"
#include "ui_administrador_visualizar_cancelacion_cita.h"

administrador_visualizar_cancelacion_cita::administrador_visualizar_cancelacion_cita(QString idMedico, QString motivo, QString cita, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administrador_visualizar_cancelacion_cita)
{
    ui->setupUi(this);

    this->idMedico = idMedico;
    this->cita = cita;
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
        qDebug() << "ERROR";
    }else{
        qDebug() << "base de datos sigue conectada en VISUALIZAR CANCELACION";
    }

    ui->idMedico->setText(idMedico);
    ui->motivo->setPlainText(motivo);
}

administrador_visualizar_cancelacion_cita::~administrador_visualizar_cancelacion_cita()
{
    delete ui;
}


void administrador_visualizar_cancelacion_cita::on_pbtn_cancelarRechazo_clicked()
{
    QSqlQuery query;
    QString sql;

    sql = "update cita_medica set estado = 1 where id_cita_medica = "+this->cita+";";
    query.exec(sql);

    this->close();
}
