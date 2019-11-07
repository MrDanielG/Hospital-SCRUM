#include "administrador_tarjeta_cancelacion_cita.h"
#include "ui_administrador_tarjeta_cancelacion_cita.h"
#include "Widgets/Administrador/administrador_visualizar_cancelacion_cita.h"
#include <QLayoutItem>
#include "Widgets/Administrador/administrador_catalogo_cancelacion_cita.h"

administrador_tarjeta_cancelacion_cita::administrador_tarjeta_cancelacion_cita(QString nombre, QString paterno, QString materno, QString motivo, QString hInicio, QString hFin, QString foto, QString cita, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::administrador_tarjeta_cancelacion_cita)
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

    this->nombre = nombre;
    this->paterno = paterno;
    this->materno = materno;
    this->motivo = motivo;
    this->hInicio = hInicio;
    this->hFin = hFin;
    this->foto = foto;
    this->cita = cita;
}

administrador_tarjeta_cancelacion_cita::~administrador_tarjeta_cancelacion_cita()
{
    delete ui;
}

void administrador_tarjeta_cancelacion_cita::insertarDatos()
{
    QString nombreCompleto = this->nombre+" "+this->paterno+" "+this->materno;
    QString horario = this->hInicio+" - "+this->hFin;
    QPixmap imag(this->foto);

    ui->lbl_foto_admin_cancelar_cita->setPixmap(imag);
    ui->lbl_nombre_admin_tarjeta_horario->setText(nombreCompleto);
    ui->lbl_motivo_admin_cancelar_cita->setText(motivo);
    ui->lbl_horario_admin_cancelar_cita->setText(horario);
    ui->lbl_idCita_admin_cancelar_cita->setText(cita);

}



void administrador_tarjeta_cancelacion_cita::on_btn_admin_visualizar_cancelacion_cita_clicked()
{
    QSqlQuery query;
    QString sql;

    QString id, justificacion;
    sql = "select id_medico, justificacion_rechazo from cita_medica where id_cita_medica = "+this->cita+";";
    query.exec(sql);

    while (query.next()) {
        id = query.value(0).toString();
        justificacion = query.value(1).toString();
    }
    administrador_visualizar_cancelacion_cita dialogo_visualizacion(id, justificacion, this->cita);
    dialogo_visualizacion.exec();

}
