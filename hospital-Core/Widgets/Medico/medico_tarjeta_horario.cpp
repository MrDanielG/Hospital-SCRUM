#include "medico_tarjeta_horario.h"
#include "ui_medico_tarjeta_horario.h"
#include "Widgets/Medico/medico_info_cita_medica.h"

medico_tarjeta_horario::medico_tarjeta_horario(QString nombre, QString paterno, QString materno, QString motivo, QString hInicio, QString hFin, QString foto,QString idCita, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::medico_tarjeta_horario)
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
    this->idCita=idCita;
}

medico_tarjeta_horario::~medico_tarjeta_horario()
{
    delete ui;
}

void medico_tarjeta_horario::insertarDatos(){

    QString nombreCompleto = this->nombre+" "+this->paterno+" "+this->materno;
    QString horario = this->hInicio+" - "+this->hFin;
    QPixmap imag(this->foto);

    ui->lbl_foto_medico_gestionar_horario->setPixmap(imag);
    ui->lbl_nombre_medico_tarjeta_horario->setText(nombreCompleto);
    ui->lbl_motivo_medico_tarjeta_horario->setText(motivo);
    ui->lb_hora_medico_tarjeta_horario->setText(horario);

}
// QString nombre, QString paterno, QString materno,QString hInicio, QString hFin, QString foto,QString idCita,
void medico_tarjeta_horario::on_btn_gestionar_medico_tarjeta_horario_clicked()
{
    qDebug()<<"idCita Medico_tarjeta_horario: " <<this->idCita;
    medico_info_cita_medica *infoCitaMedica = new medico_info_cita_medica(this->nombre,this->paterno,this->materno,this->hInicio,this->hFin,this->foto,this->idCita);
    infoCitaMedica->show();
}
