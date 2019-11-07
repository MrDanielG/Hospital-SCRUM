#include "paciente_gestionar_citas.h"
#include "ui_paciente_gestionar_citas.h"
#include "Widgets/Paciente/paciente_tarjeta_cita.h"
#include "QMessageBox"
#include "QDebug"
#include "QSqlQuery"

paciente_gestionar_citas::paciente_gestionar_citas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::paciente_gestionar_citas)
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
        qDebug() << "ERROR con Base de Datos, esto es: GESTIONAR CITAS";
        return;
    }else{
        qDebug() << "Base de datos continua abierta, esto es: GESTIONAR CITAS";
    }
}

paciente_gestionar_citas::~paciente_gestionar_citas()
{
    delete ui;
}

void paciente_gestionar_citas::setIdPaciente(QString _idUsuarioPaciente)
{
    this->idUsuarioPaciente = _idUsuarioPaciente;
    inicalizaCatalogo();
}

void paciente_gestionar_citas::inicalizaCatalogo()
{
    QSqlQuery citas(mDatabase);
    citas.prepare("SELECT * FROM `gestioncitas` WHERE id_usuario = '"+this->idUsuarioPaciente+"'");
    citas.exec();
    limpiarCatalogo();

    int i = 0;
    int row = 0;
    int col = 0;

    while (citas.next())
    {
        QString id_cita = citas.value(0).toString();
        QString descripcion = citas.value(1).toString();
        QString fecha = citas.value(2).toString();
        QString horaInicioFin = citas.value(3).toString() + " " + citas.value(4).toString();
        QString estadoCita = citas.value(6).toString();
        QString nombreMedico = citas.value(7).toString() + " " + citas.value(8).toString() + " " + citas.value(9).toString();
        QString nombreUsuario = citas.value(10).toString();

        row = i / 3;
        col = i % 3;

        paciente_tarjeta_cita *tarjeta = new paciente_tarjeta_cita(id_cita, descripcion, fecha, horaInicioFin, estadoCita, nombreMedico, nombreUsuario, this);
        i++;
        ui->gridLayout->addWidget(tarjeta, row, col);
    }
}

void paciente_gestionar_citas::limpiarCatalogo()
{
    while (QLayoutItem *item = ui->gridLayout->takeAt(0))
    {
        Q_ASSERT(!item->layout()); // otherwise the layout will leak
        delete item->widget();
        delete item;
    }
}
