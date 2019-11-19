#include "paciente_gestionar_citas.h"
#include "ui_paciente_gestionar_citas.h"
#include "Widgets/Paciente/paciente_tarjeta_cita.h"
#include "Widgets/Paciente/paciente_crear_cita.h"
#include "QMessageBox"
#include "QDebug"
#include "QSqlQuery"
#include <QPixmap>
#include <QDate>
#include "QDateTime"

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

    //ocultar
    ui->buscar->hide();
    ui->label_foto->hide();
    ui->label_5->hide();
    ui->label_cedula->hide();
    ui->label_9->hide();
    ui->label_nombre->hide();
    ui->label_experiencia->hide();
    ui->label_correo->hide();
    ui->label_logros->hide();
    ui->label_hora->hide();
    ui->label_6->hide();
    ui->label_7->hide();
    ui->label_11->hide();
    ui->label_13->hide();
    ui->label_8->hide();
    ui->btn_agenda_cita->hide();

    //Para el comboBox de os doctores generales
    QSqlQuery doctores(mDatabase);
    doctores.prepare("select concat(p.nombre,' ',p.paterno,' ',p.materno) as Medico from persona as p "
                     "inner join empleado as e on p.id_persona=e.id_persona "
                     "inner join medico as m on e.id_empleado=m.id_empleado "
                     "inner join medico_has_especialidad as me on m.id_medico=me.id_medico "
                     "where me.id_especialidad=1;");
    doctores.exec();
    while(doctores.next())
    {
        ui->comboMedicos->addItem(doctores.value(0).toString());
    }
    QString Doc;
    Doc = ui->comboMedicos->currentText();
    inicalizaCatalogo();
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
    on_btn_citas_activas_clicked();
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

void paciente_gestionar_citas::on_btn_agenda_cita_clicked()
{
    paciente_crear_cita crearCita(this->idDoc,this->idUsuarioPaciente);
    crearCita.exec();
    inicalizaCatalogo();
}

void paciente_gestionar_citas::on_comboMedicos_activated(const QString &Doc)
{
    QString foto,cedula,nombre,correo,exp,logro;
    QSqlQuery DetalleDoc(mDatabase);
    DetalleDoc.prepare("call InfoDoc('"+Doc+"');");
    DetalleDoc.exec();
    while(DetalleDoc.next())
    {
        foto=DetalleDoc.value(0).toString();
        cedula=DetalleDoc.value(1).toString();
        nombre=DetalleDoc.value(2).toString();
        correo=DetalleDoc.value(3).toString();
        exp=DetalleDoc.value(4).toString();
        logro=DetalleDoc.value(5).toString();
        idDoc=DetalleDoc.value(6).toString();
    }

    QPixmap pic(foto);
    ui->label_foto->setPixmap(pic);
    ui->label_cedula->setText(cedula);
    ui->label_nombre->setText(nombre);
    ui->label_correo->setText(correo);
    ui->label_experiencia->setText(exp);
    ui->label_logros->setText(logro);

    ui->label_foto->show();
    ui->label_5->show();
    ui->label_cedula->show();
    ui->label_9->show();
    ui->label_nombre->show();
    ui->label_experiencia->show();
    ui->label_correo->show();
    ui->label_logros->show();
    ui->label_hora->show();
    ui->label_6->show();
    ui->label_7->show();
    ui->label_11->show();
    ui->label_13->show();
    ui->label_8->show();
    ui->btn_agenda_cita->show();
}

void paciente_gestionar_citas::on_btn_citas_activas_clicked()
{
    bool band=false;
    QSqlQuery BuscaID(mDatabase);
    QTime horaActual=QTime::currentTime();
    BuscaID.prepare("select id_paciente from paciente as p inner join persona as per "
                    "on p.id_persona=per.id_persona where per.nombre='"+idUsuarioPaciente+"';");
    BuscaID.exec();
    QString idP;
    while(BuscaID.next())
    {
        idP = BuscaID.value(0).toString();
    }

    QDate date = QDate::currentDate();
    QString hoy = date.toString("yyyy-MM-dd");
    QSqlQuery BuscaActivas(mDatabase);
    BuscaActivas.prepare("select * from cita_medica where fecha >= '"+hoy+"' and estado=1 and id_paciente='"+idP+"';");
    BuscaActivas.exec();

    limpiarCatalogo();

    int i = 0;
    int row = 0;
    int col = 0;

    while (BuscaActivas.next())
    {

        if((BuscaActivas.value(4).toTime()>horaActual))
        {
            band=true;
        }else
        {
            if(BuscaActivas.value(3).toDate()>date)
            {
                band=true;
            }
        }

        QString id_cita = BuscaActivas.value(0).toString();
        QString motivo = BuscaActivas.value(1).toString();
        QString descripcion = BuscaActivas.value(2).toString();
        QString fecha = BuscaActivas.value(3).toString();
        //QString horaInicioFin = BuscaActivas.value(4).toString() + " " +  BuscaActivas.value(5).toString();
        QTime horaInicio = BuscaActivas.value(4).toTime();
        QTime horaFin = BuscaActivas.value(5).toTime();
        QString horaInicioFin = horaInicio.toString("hh:mm") + " - " + horaFin.toString("hh:mm");
        QString idMed = BuscaActivas.value(6).toString();
        QString idPac = BuscaActivas.value(7).toString();
        QString idPago = BuscaActivas.value(8).toString();
        QString estadoCita = BuscaActivas.value(9).toString();
        QString calif = BuscaActivas.value(10).toString();

        row = i / 2;
        col = i % 2;

        if(band)
        {
            paciente_tarjeta_cita *tarjeta = new paciente_tarjeta_cita(id_cita, motivo, descripcion, fecha, horaInicioFin, idMed, idPac, idPago, estadoCita,calif,this);
            tarjeta->ocultarBotonCalificar();
            i++;
            ui->gridLayout->addWidget(tarjeta, row, col);
        }

        band=false;

    }
}

void paciente_gestionar_citas::on_btn_citas_realizadas_clicked()
{
    QSqlQuery BuscaID(mDatabase);
    BuscaID.prepare("select id_paciente from paciente as p inner join persona as per "
                    "on p.id_persona=per.id_persona where per.nombre='"+idUsuarioPaciente+"';");
    BuscaID.exec();
    QString idP;
    //bool band=false;
    while(BuscaID.next())
    {
        idP = BuscaID.value(0).toString();
    }

    QDate date = QDate::currentDate();
    QTime horaActual=QTime::currentTime();
    QString hoy = date.toString("yyyy-MM-dd");
    QString time = horaActual.toString("hh:mm");
    QSqlQuery BuscaRealizadas(mDatabase);
    BuscaRealizadas.prepare("select * from cita_medica where fecha <= '"+hoy+"' and estado=1 and id_paciente='"+idP+"';");
    BuscaRealizadas.exec();

    limpiarCatalogo();

    int i = 0;
    int row = 0;
    int col = 0;

    while (BuscaRealizadas.next())
    {
        /*if(BuscaRealizadas.value(4).toTime()<horaActual)
        {
            band=true;
        }

        qDebug()<<"bandera"<<band;*/

        QString id_cita = BuscaRealizadas.value(0).toString();
        QString motivo = BuscaRealizadas.value(1).toString();
        QString descripcion = BuscaRealizadas.value(2).toString();
        QString fecha = BuscaRealizadas.value(3).toString();
        //QString horaInicioFin = BuscaRealizadas.value(4).toString() + " " +  BuscaRealizadas.value(5).toString();
        QTime horaInicio = BuscaRealizadas.value(4).toTime();
        QTime horaFin = BuscaRealizadas.value(5).toTime();
        QString horaInicioFin = horaInicio.toString("hh:mm") + " - " + horaFin.toString("hh:mm");
        QString idMed = BuscaRealizadas.value(6).toString();
        QString idPac = BuscaRealizadas.value(7).toString();
        QString idPago = BuscaRealizadas.value(8).toString();
        QString estadoCita = BuscaRealizadas.value(9).toString();
        QString calif = BuscaRealizadas.value(10).toString();

        row = i / 2;
        col = i % 2;
        //if(band)
        //{
            paciente_tarjeta_cita *tarjeta = new paciente_tarjeta_cita(id_cita, motivo, descripcion, fecha, horaInicioFin, idMed, idPac, idPago, estadoCita, calif, this);
            if(calif == "0")
            {
                tarjeta->ocultarBoton();
            }else
            {
                tarjeta->ocultarAmobosBotones();
            }

            i++;
            ui->gridLayout->addWidget(tarjeta, row, col);
        //}
        //band=false;
    }
}

void paciente_gestionar_citas::on_btn_citas_canceladas_clicked()
{
    QSqlQuery BuscaID(mDatabase);
    BuscaID.prepare("select id_paciente from paciente as p inner join persona as per "
                    "on p.id_persona=per.id_persona where per.nombre='"+idUsuarioPaciente+"';");
    BuscaID.exec();
    QString idP;
    while(BuscaID.next())
    {
        idP = BuscaID.value(0).toString();
    }

    /*El estado de la cita es 3 cuando esta cancelada por el paciente*/
    QSqlQuery BuscaCanceladas(mDatabase);
    BuscaCanceladas.prepare("select * from cita_medica where estado=3 and id_paciente='"+idP+"';");
    BuscaCanceladas.exec();

    limpiarCatalogo();

    int i = 0;
    int row = 0;
    int col = 0;

    while (BuscaCanceladas.next())
    {
        QString id_cita = BuscaCanceladas.value(0).toString();
        QString motivo = BuscaCanceladas.value(1).toString();
        QString descripcion = BuscaCanceladas.value(2).toString();
        QString fecha = BuscaCanceladas.value(3).toString();
        //QString horaInicioFin = BuscaCanceladas.value(4).toString() + " " +  BuscaCanceladas.value(5).toString();
        QTime horaInicio = BuscaCanceladas.value(4).toTime();
        QTime horaFin = BuscaCanceladas.value(5).toTime();
        QString horaInicioFin = horaInicio.toString("hh:mm") + " - " + horaFin.toString("hh:mm");
        QString idMed = BuscaCanceladas.value(6).toString();
        QString idPac = BuscaCanceladas.value(7).toString();
        QString idPago = BuscaCanceladas.value(8).toString();
        QString estadoCita = BuscaCanceladas.value(9).toString();
        QString calif = BuscaCanceladas.value(10).toString();

        row = i / 2;
        col = i % 2;

        paciente_tarjeta_cita *tarjeta = new paciente_tarjeta_cita(id_cita, motivo, descripcion, fecha, horaInicioFin, idMed, idPac, idPago, estadoCita, calif, this);
        tarjeta->ocultarAmobosBotones();

        i++;
        ui->gridLayout->addWidget(tarjeta, row, col);
    }
}
