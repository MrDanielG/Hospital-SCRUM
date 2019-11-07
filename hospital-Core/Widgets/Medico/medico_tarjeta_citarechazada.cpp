#include "medico_tarjeta_citarechazada.h"
#include "ui_medico_tarjeta_citarechazada.h"

medico_tarjeta_CitaRechazada::medico_tarjeta_CitaRechazada(QString nombre, QString paterno, QString materno, QString motivo, QString hInicio, QString hFin, QString foto,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::medico_tarjeta_CitaRechazada)
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
    if (!mDatabase.isOpen()){
        qDebug() << "ERROR";
    }else{
        qDebug() << "base de datos sigue conectada en TARJETA_SOLICITUD";
    }
    this->nombre = nombre;
    this->paterno = paterno;
    this->materno = materno;
    this->motivo = motivo;
    this->hInicio = hInicio;
    this->hFin = hFin;
    this->foto = foto;

}

medico_tarjeta_CitaRechazada::~medico_tarjeta_CitaRechazada()
{
    delete ui;
}

void medico_tarjeta_CitaRechazada::insertarDatos()
{
    QString nombreCompleto = this->nombre+" "+this->paterno+" "+this->materno;
    QString horario = this->hInicio+" - "+this->hFin;
    QPixmap imag(this->foto);

    ui->lbl_nombre_solicitudes->setText(nombreCompleto);
    ui->lbl_foto_solicitudes->setPixmap(imag);
    ui->lbl_horario_solicitudes->setText(horario);
    ui->lbl_sintoma_solicitudes->setText(motivo);

}
