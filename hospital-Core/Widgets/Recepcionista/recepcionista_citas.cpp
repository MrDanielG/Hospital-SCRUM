#include "recepcionista_citas.h"
#include "ui_recepcionista_citas.h"
#include <QMessageBox>

recepcionista_citas::recepcionista_citas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::recepcionista_citas)
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
    mostrarCitas();



}

recepcionista_citas::~recepcionista_citas()
{
    delete ui;
}

void recepcionista_citas::insertarDatos()
{

}



void recepcionista_citas::on_btnCitas_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void recepcionista_citas::on_btnCitas_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void recepcionista_citas::on_lineEdit_2_textChanged(const QString &arg1)
{
    QString fecha = ui->lineEdit->text();
    char caracter = '%';

    if(seccionactivada == 1){
        QSqlQuery MostrarDatos(mDatabase);
        MostrarDatos.prepare("select cita.fecha, cita.hora_inicio, persona.nombre, persona.paterno "
                             "From persona INNER JOIN empleado "
                             "ON persona.id_persona = empleado.id_persona "
                             "INNER JOIN medico "
                             "ON empleado.id_empleado = medico.id_empleado "
                             "INNER JOIN cita_medica as cita "
                             "ON medico.id_medico = cita.id_medico "
                             "where persona.nombre like '"+arg1+""+caracter+"' and persona.nombre like '"+fecha+""+caracter+"'");
        MostrarDatos.exec();

        int row = 0;
        int col = 0;
        int i=0;
        limpiarCatalogo();

        while (MostrarDatos.next()){
            QString fecha = MostrarDatos.value(0).toString();
            QString hora = MostrarDatos.value(1).toString();
            QString medico = MostrarDatos.value(2).toString();
            QString medicopaterno = MostrarDatos.value(3).toString();
            row = i/2;
            col= i%2;

            recepcion_tarjeta_citas *tarjeta = new recepcion_tarjeta_citas();
            tarjeta->insertarDatos(fecha, hora, medico, medicopaterno);
            i++;
            ui->gridLayout->addWidget(tarjeta, row, col);
        }
    }else{

        QSqlQuery MostrarDatos(mDatabase);
        MostrarDatos.prepare("select operaciones.fecha, persona.nombre, persona.paterno "
                             " FROM persona INNER JOIN empleado "
                             "ON persona.id_persona = empleado.id_persona "
                             "INNER JOIN medico "
                             "ON empleado.id_empleado = medico.id_empleado "
                             "INNER JOIN operaciones_agendadas as operaciones "
                             "ON medico.id_medico = operaciones.id_medico "
                             "where persona.nombre like '"+arg1+""+caracter+"' and operaciones.fecha like '"+fecha+""+caracter+"'");
        MostrarDatos.exec();
        int row = 0;
        int col = 0;
        int i=0;
        limpiarCatalogo();

        while (MostrarDatos.next()){
            QString fecha = MostrarDatos.value(0).toString();
            QString hora = MostrarDatos.value(1).toString();
            QString medico = MostrarDatos.value(2).toString();
            QString medicopaterno = MostrarDatos.value(3).toString();
            row = i/2;
            col= i%2;

            recepcion_tarjeta_citas *tarjeta = new recepcion_tarjeta_citas();
            tarjeta->insertarDatos(fecha, hora, medico, medicopaterno);
            i++;
            ui->gridLayout->addWidget(tarjeta, row, col);
        }
    }


}

void recepcionista_citas::limpiarCatalogo(){
    while ( QLayoutItem* item = ui->gridLayout->takeAt( 0 ) ){
            Q_ASSERT( ! item->layout() ); // otherwise the layout will leak
            delete item->widget();
            delete item;
    }
}

void recepcionista_citas::mostrarCitas()
{
    ui->seccion->setText("Citas");
    QSqlQuery MostrarDatos(mDatabase);

    MostrarDatos.prepare("select cita.fecha, cita.hora_inicio, persona.nombre, persona.paterno "
                         "From persona INNER JOIN empleado "
                         "ON persona.id_persona = empleado.id_persona "
                         "INNER JOIN medico "
                         "ON empleado.id_empleado = medico.id_empleado "
                         "INNER JOIN cita_medica as cita "
                         "ON medico.id_medico = cita.id_medico ");
    MostrarDatos.exec();
    int i=0;
    int row = 0;
    int col = 0;

    while (MostrarDatos.next()){
        QString fecha = MostrarDatos.value(0).toString();
        QString hora = MostrarDatos.value(1).toString();
        QString medico = MostrarDatos.value(2).toString();
        QString medicopaterno = MostrarDatos.value(3).toString();
        row = i/2;
        col= i%2;

        recepcion_tarjeta_citas *tarjeta = new recepcion_tarjeta_citas();
        tarjeta->insertarDatos(fecha, hora, medico, medicopaterno);
        i++;
        ui->gridLayout->addWidget(tarjeta, row, col);
    }

}

void recepcionista_citas::mostrarOperaciones()
{
    ui->seccion->setText("Operaciones");
    QSqlQuery MostrarDatos(mDatabase);

    MostrarDatos.prepare("select operaciones.fecha, persona.nombre, persona.paterno "
                         " FROM persona INNER JOIN empleado "
                         "ON persona.id_persona = empleado.id_persona "
                         "INNER JOIN medico "
                         "ON empleado.id_empleado = medico.id_empleado "
                         "INNER JOIN operaciones_agendadas as operaciones "
                         "ON medico.id_medico = operaciones.id_medico");

    MostrarDatos.exec();
    int i=0;
    int row = 0;
    int col = 0;

    while (MostrarDatos.next()){
        QString fecha = MostrarDatos.value(0).toString();
        QString hora = "04:14:10";
        QString medico = MostrarDatos.value(1).toString();
        QString medicopaterno = MostrarDatos.value(2).toString();
        row = i/2;
        col= i%2;

        recepcion_tarjeta_citas *tarjeta = new recepcion_tarjeta_citas();
        tarjeta->insertarDatos(fecha, hora, medico, medicopaterno);
        i++;
        ui->gridLayout->addWidget(tarjeta, row, col);
    }
}

void recepcionista_citas::on_lineEdit_textChanged(const QString &arg1)
{
    QString nombre = ui->lineEdit_2->text();
    qDebug()<<nombre+" este es el nombre";
    char caracter = '%';

    if(seccionactivada==1){
        QSqlQuery MostrarDatos(mDatabase);
        MostrarDatos.prepare("select cita.fecha, cita.hora_inicio, persona.nombre, persona.paterno "
                             "From persona INNER JOIN empleado "
                             "ON persona.id_persona = empleado.id_persona "
                             "INNER JOIN medico "
                             "ON empleado.id_empleado = medico.id_empleado "
                             "INNER JOIN cita_medica as cita "
                             "ON medico.id_medico = cita.id_medico "
                             "where cita.fecha like '"+arg1+""+caracter+"' and persona.nombre like '"+nombre+""+caracter+"'");
        MostrarDatos.exec();

        int row = 0;
        int col = 0;
        int i=0;
        limpiarCatalogo();

        while (MostrarDatos.next()){
            QString fecha = MostrarDatos.value(0).toString();
            QString hora = MostrarDatos.value(1).toString();
            QString medico = MostrarDatos.value(2).toString();
            QString medicopaterno = MostrarDatos.value(3).toString();
            row = i/2;
            col= i%2;

            recepcion_tarjeta_citas *tarjeta = new recepcion_tarjeta_citas();
            tarjeta->insertarDatos(fecha, hora, medico, medicopaterno);
            i++;
            ui->gridLayout->addWidget(tarjeta, row, col);
        }
    }else{
        QSqlQuery MostrarDatos(mDatabase);
        MostrarDatos.prepare("select operaciones.fecha, persona.nombre, persona.paterno "
                             " FROM persona INNER JOIN empleado "
                             "ON persona.id_persona = empleado.id_persona "
                             "INNER JOIN medico "
                             "ON empleado.id_empleado = medico.id_empleado "
                             "INNER JOIN operaciones_agendadas as operaciones "
                             "ON medico.id_medico = operaciones.id_medico "
                             "where operaciones.fecha like '"+arg1+""+caracter+"' and persona.nombre like '"+nombre+""+caracter+"'");
        MostrarDatos.exec();
        int row = 0;
        int col = 0;
        int i=0;
        limpiarCatalogo();

        while (MostrarDatos.next()){
            QString fecha = MostrarDatos.value(0).toString();
            QString hora = MostrarDatos.value(1).toString();
            QString medico = MostrarDatos.value(2).toString();
            QString medicopaterno = MostrarDatos.value(3).toString();
            row = i/2;
            col= i%2;

            recepcion_tarjeta_citas *tarjeta = new recepcion_tarjeta_citas();
            tarjeta->insertarDatos(fecha, hora, medico, medicopaterno);
            i++;
            ui->gridLayout->addWidget(tarjeta, row, col);
        }
    }



}

void recepcionista_citas::on_btnCitas_clicked()
{
    limpiarCatalogo();
    mostrarCitas();
    seccionactivada=1;

}

void recepcionista_citas::on_btnCitas_2_clicked()
{
    limpiarCatalogo();
    mostrarOperaciones();
    seccionactivada=2;
}

void recepcionista_citas::on_btn_agendarCita_clicked()
{
    if(ui->lineEdit_descripcion->text().isEmpty() &&
            ui->lineEdit_motivo->text().isEmpty()){
        QMessageBox::warning(this, tr("Error Info"),tr("Datos no Coinciden.\nIngresar todos los datos solicitados"),
                                      QMessageBox::Ok);
    } else {
        QString folioMedico = ui->line_id_medico->text();
        QString motivo = ui->lineEdit_motivo->text();
        QString descripcion = ui->lineEdit_descripcion->text();
        QString fecha = ui->dateEdit->date().toString("dd/MM/yyyy");
        QString horaInicio = ui->timeEdit_HoraInicio->time().toString();
        QString horaFinal = ui->timeEdit_HoraFinal->time().toString();
        QString idPaciente = ui->line_id_paciente->text();

        QSqlQuery crearCita(mDatabase);

        crearCita.prepare("INSERT INTO cita_medica(motivo, descripcion, fecha, hora_inicio, hora_fin, id_medico, id_paciente, estado) "
                          "VALUES ('"+motivo+"','"+descripcion+"','"+fecha+"','"+horaInicio+"','"+horaFinal+"','"+folioMedico+"','"+idPaciente+"', '1')");
        crearCita.exec();

        QMessageBox::information(this, tr("Registrar Cita"),tr("Cita Registrada Correctamente"),
                                      QMessageBox::Ok);
        limpiarCatalogo();
        mostrarCitas();

    }
}

void recepcionista_citas::on_operacion_btn_agendar_clicked()
{

        QString id_medico = ui->operacion_id_medico->text();
        QString id_paciente = ui->operacion_id_paciente->text();
        QString descripcion = ui->operacion_descripcion->text();
        QString fecha = ui->operacion_fecha->date().toString("yyyy/MM/dd");
        QString horaini = ui->operacion_hora_ini->time().toString();
        QString horafin = ui->operacion_hora_fin->time().toString();
        QString lugar = ui->operacion_lugar->text();
        QString recepcionista = "1";


        QSqlQuery crearCita(mDatabase);

        crearCita.prepare("insert into operaciones_agendadas (descripcion, lugar, fecha, id_paciente, id_recepcionista, id_medico) values "
                          "('"+descripcion+"','"+lugar+"','"+fecha+"',"+id_paciente+","+recepcionista+","+id_medico+") ");
        crearCita.exec();

        QMessageBox::information(this, tr("Agendar Operacion"),tr("Operacion Registrada Correctamente"),
                                      QMessageBox::Ok);
        limpiarCatalogo();
        mostrarOperaciones();

}
