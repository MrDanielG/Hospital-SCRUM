#include "medico_tarjeta_horario.h"
#include "ui_medico_tarjeta_horario.h"

medico_tarjeta_horario::medico_tarjeta_horario(QString nombre, QString paterno, QString materno, QString motivo, QString hInicio, QString hFin, QString foto, QWidget *parent) :
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
          qDebug()<<"Error Base de Datos, esto es: ADMINISTRADOR TARJETA SERVICIOS";
           return;
    }else{
            qDebug()<<"Base de datos continua abierta, esto es: ADMINISTRADOR TARJETA SERVICIOS";
    }

    this->nombre = nombre;
    this->paterno = paterno;
    this->materno = materno;
    this->motivo = motivo;
    this->hInicio = hInicio;
    this->hFin = hFin;
    this->foto = foto;
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
