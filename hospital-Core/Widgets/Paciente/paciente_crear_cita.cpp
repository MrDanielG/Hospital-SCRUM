#include "paciente_crear_cita.h"
#include "ui_paciente_crear_cita.h"
#include "QMessageBox"
#include "QDebug"
#include "QSqlQuery"
paciente_crear_cita::paciente_crear_cita(QString usuario, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::paciente_crear_cita)
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
        qDebug() << "ERROR con Base de Datos, esto es: CREAR CITAS";
        return;
    }else{
        qDebug() << "Base de datos continua abierta, esto es: CREAR CITAS";
    }

    this->idUsuarioPaciente = usuario;

    QSqlQuery query(mDatabase);
    query.prepare("Select id_medico from medico");
    query.exec();
    int i = 0;
    while (query.next()) {
        i++;
        QString idMedico1 = query.value(0).toString();
        qDebug()<< "ids de Medicos xd" << idMedico1;
        ui->comboBox_idMedico->insertItem(i,idMedico1);
    }
}

paciente_crear_cita::~paciente_crear_cita()
{
    delete ui;
}

void paciente_crear_cita::on_btn_agendarCita_clicked()
{
    if(ui->lineEdit_descripcion->text().isEmpty() &&
            ui->lineEdit_motivo->text().isEmpty()){
        QMessageBox::warning(this, tr("Error Info"),tr("Datos no Coinciden.\nIngresar todos los datos solicitados"),
                                      QMessageBox::Ok);
    } else {
        QString folioMedico = ui->comboBox_idMedico->currentText();
        QString motivo = ui->lineEdit_motivo->text();
        QString descripcion = ui->lineEdit_descripcion->text();
        QString fecha = ui->dateEdit->date().toString("dd/MM/yyyy");
        QString horaInicio = ui->timeEdit_HoraInicio->time().toString();
        QString horaFinal = ui->timeEdit_HoraFinal->time().toString();

        QSqlQuery queryIdPaciente(mDatabase);
        queryIdPaciente.prepare("SELECT * FROM `paciente` INNER JOIN persona ON paciente.id_persona = persona.id_persona INNER JOIN usuario ON persona.id_usuario = usuario.id_usuario WHERE usuario.id_usuario = '"+this->idUsuarioPaciente+"'");
        queryIdPaciente.exec();
        queryIdPaciente.next();
        QString idPaciente = queryIdPaciente.value(0).toString();
        qDebug()<<"datos xd" <<motivo<<descripcion<<fecha<<horaInicio<<horaFinal<<folioMedico<<idPaciente;
        QSqlQuery crearCita(mDatabase);
        crearCita.prepare("INSERT INTO `cita_medica`(`motivo`, `descripcion`, `fecha`, `hora_inicio`, `hora_fin`, `id_medico`, `id_paciente`, `estado`) "
                          "VALUES ('"+motivo+"','"+descripcion+"','"+fecha+"','"+horaInicio+"','"+horaFinal+"','"+folioMedico+"','"+idPaciente+"',1)");
        crearCita.exec();

        QMessageBox::information(this, tr("Registrar Cita"),tr("Cita Registrada Correctamente"),
                                      QMessageBox::Ok);
        this->close();

    }
}
