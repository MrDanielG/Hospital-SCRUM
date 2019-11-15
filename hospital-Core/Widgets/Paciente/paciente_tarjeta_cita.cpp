#include "paciente_tarjeta_cita.h"
#include "ui_paciente_tarjeta_cita.h"
#include "QDebug"
#include <QSqlQuery>
#include <QDate>
#include <QMessageBox>
#include "paciente_califica_medico.h"
#include "Widgets/Paciente/paciente_reagendar_cita.h"
#include "Widgets/Paciente/paciente_crear_cita.h"

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
    QSqlQuery NombreM(mDatabase);
    NombreM.prepare("select concat(p.nombre,' ',p.paterno,' ',p.materno) as Nombre from persona as p "
                    "inner join empleado as e on p.id_persona=e.id_persona "
                    "inner join medico as m on e.id_empleado=m.id_empleado "
                    "where m.id_medico='"+this->idMed+"';");
    NombreM.exec();
    QString nom;
    while(NombreM.next())
    {
        nom = NombreM.value(0).toString();
    }

    ui->label_folio->setText(this->id_cita);
    ui->lbl_fecha_cita->setText(this->fecha);
    ui->lbl_nombre_medico->setText(nom);
    ui->lbl_horario->setText(this->horaInicioFin);
    ui->info_cita->setPlainText(this->descripcion);
    ui->lbl_motivo->setText(this->motivo);

    QDate date = QDate::currentDate();
    QString hoy = date.toString("yyyy-MM-dd");

    if(this->fecha < hoy || this->estadoCita == '3')
    {
        ui->btn_gestionar->hide();
    }
}

//Para cancelar una cita por el paciente
void paciente_tarjeta_cita::on_btn_gestionar_clicked()
{
    paciente_Reagendar_cita mensajeReagendar(this);
    mensajeReagendar.exec();
    QMessageBox::StandardButton Confirmacion;

    if(mensajeReagendar.getBand())
    {
        paciente_crear_cita crearCita(this->id_cita,"reagendar");
        crearCita.exec();



    }else
    {
        Confirmacion = QMessageBox::question(this, "ADVERTENCIA", "¿Está seguro de cancelar esta cita?",
                                            QMessageBox::Yes | QMessageBox::No);
        if(Confirmacion == QMessageBox::Yes)
        {
            QSqlQuery CancelaCita(mDatabase);
            CancelaCita.prepare("update cita_medica set estado=3 where id_cita_medica='"+id_cita+"';");
            CancelaCita.exec();

            QMessageBox::information(this, tr("Cita"),tr("Cita cancelada"),
                                          QMessageBox::Ok);
            ui->btn_gestionar->hide();
        }
    }

}

void paciente_tarjeta_cita::ocultarBoton()
{
    ui->btn_gestionar->hide();
}

void paciente_tarjeta_cita::on_btn_calificar_clicked()
{
    Paciente_Califica_Medico calificando(idMed,this);
    calificando.exec();
}
