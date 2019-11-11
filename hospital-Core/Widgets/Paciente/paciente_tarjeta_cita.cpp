#include "paciente_tarjeta_cita.h"
#include "ui_paciente_tarjeta_cita.h"
#include "QDebug"
paciente_tarjeta_cita::paciente_tarjeta_cita(QString id_cita, QString motivo, QString descripcion, QString fecha, QString horaInicioFin, QString idMed,QString idPac, QString idPagos,QString estadoCita, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::paciente_tarjeta_cita)
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
        qDebug() << "ERROR con Base de Datos, esto es: TARJETA CITAS";
        return;
    }else{
        qDebug() << "Base de datos continua abierta, esto es: TARJETA CITAS";
    }

    this->id_cita = id_cita;
    this->motivo = motivo;
    this->descripcion = descripcion;
    this->fecha = fecha;
    this->horaInicioFin = horaInicioFin;
    this->idMed = idMed;
    this->idPac = idPac;
    this->idPagos = idPagos;
    this->estadoCita = estadoCita;

    inicializarTarjeta();
}

paciente_tarjeta_cita::~paciente_tarjeta_cita()
{
    delete ui;
}

void paciente_tarjeta_cita::inicializarTarjeta()
{
    ui->lbl_fecha_cita->setText(this->fecha);
    ui->lbl_nombre_medico->setText(this->nombreMedico);
    ui->lbl_horario->setText(this->horaInicioFin);
    ui->info_cita->setPlainText(this->descripcion);
}

void paciente_tarjeta_cita::on_btn_gestionar_clicked()
{

}
