#include "administrador_visualizar_cancelacion_cita.h"
#include "ui_administrador_visualizar_cancelacion_cita.h"
#include "QMessageBox"
administrador_visualizar_cancelacion_cita::administrador_visualizar_cancelacion_cita(QString idMedico, QString motivo, QString cita, QString hInicio, QString hFin, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administrador_visualizar_cancelacion_cita)
{
    ui->setupUi(this);

    this->idMedico = idMedico;
    this->cita = cita;
    this->hInicio = hInicio;
    this->hFin = hFin;

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
    QSqlQuery query(mDatabase);
    QString sql;
    sql = "update cita_medica set estado = 1 where id_cita_medica = "+this->cita+";";
    query.exec(sql);

    QMessageBox::information(this, tr("Actualizacion"),tr("La cita no se Reasignara <br> El doctor seguira teniendo la cita"),
                                  QMessageBox::Ok);
    this->close();
}

void administrador_visualizar_cancelacion_cita::on_pbtn_aprobarRechazo_clicked()
{
    QSqlQuery query(mDatabase);
    QSqlQuery query2(mDatabase);
    QString sql;
    QString sql2;

    QString h_inicio, h_fin;
    QString idMedico;
    int contador = 0;

    sql = "select id_medico from medico;";
    query.exec(sql);
    while (query.next()) {
        idMedico = query.value(0).toString();
        sql2 = "select count(*) from cita_medica where hora_inicio = '"+this->hInicio+"' and hora_fin = '"+this->hFin+"' and id_medico = "+idMedico+";";
        query2.exec(sql2);
        while (query2.next()) {
            contador = query2.value(0).toInt();
            qDebug()<<contador;
        }
        if(contador == 0){
            break;
        }
    }

    sql = "update cita_medica set estado = 1, id_medico = "+idMedico+"where id_cita_medica = "+this->cita+";";
    query.exec(sql);

    QMessageBox::information(this, tr("Actualizacion"),tr("Estado de Cita Acutalizado<br>Se reasigno la cita a un nuevo doctor"),
                                  QMessageBox::Ok);

    this->close();
}
