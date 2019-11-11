#include "paciente_crear_cita.h"
#include "ui_paciente_crear_cita.h"
#include "QMessageBox"
#include "QDebug"
#include "QSqlQuery"
#include <QStringListModel>
#include <QList>
#include <QSet>
#include <QTime>

paciente_crear_cita::paciente_crear_cita(QString idM,QString usuario, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::paciente_crear_cita),
       horas(new QStringListModel(this))
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
    idMedico = idM;

    /*QSqlQuery query(mDatabase);
    query.prepare("Select id_medico from medico");
    query.exec();
    int i = 0;
    while (query.next()) {
        i++;
        QString idMedico1 = query.value(0).toString();
        qDebug()<< "ids de Medicos xd" << idMedico1;
        ui->comboBox_idMedico->insertItem(i,idMedico1);
    }*/

    //Para mostrar el nombre del médico que eligió cuando reserva su cita
    QSqlQuery nombre(mDatabase);
    qDebug() << idMedico;
    qDebug() << idUsuarioPaciente;
    nombre.prepare("select concat(p.nombre,' ',p.paterno,' ',p.materno) as Nombre from persona as p "
                   "inner join empleado as e on p.id_persona=e.id_persona "
                   "inner join medico as m on e.id_empleado=m.id_empleado "
                   "where id_medico='"+idMedico+"';");
    nombre.exec();
    QString nom;
    while(nombre.next())
    {
        nom = nombre.value(0).toString();
    }

    ui->label_NomMedico->setText(nom);
    ui->listHorasDisponibles->setModel(horas);
    llenarLista();
}

paciente_crear_cita::~paciente_crear_cita()
{
    delete ui;
}

void paciente_crear_cita::on_btn_agendarCita_clicked()
{
    /*if(ui->lineEdit_descripcion->text().isEmpty() &&
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
        queryIdPaciente.prepare("SELECT id_paciente FROM `gestioncitas` WHERE id_usuario = '"+this->idUsuarioPaciente+"'");
        queryIdPaciente.exec();
        queryIdPaciente.next();
        QString idPaciente = queryIdPaciente.value(0).toString();

        QSqlQuery crearCita(mDatabase);
        crearCita.prepare("INSERT INTO `cita_medica`(`motivo`, `descripcion`, `fecha`, `hora_inicio`, `hora_fin`, `id_medico`, `id_paciente`, `estado`) "
                          "VALUES ('"+motivo+"','"+descripcion+"','"+fecha+"','"+horaInicio+"','"+horaFinal+"','"+folioMedico+"','"+idPaciente+"',1)");
        crearCita.exec();

        QMessageBox::information(this, tr("Registrar Cita"),tr("Cita Registrada Correctamente"),
                                      QMessageBox::Ok);
        this->close();

    }*/

    if(ui->lineMotivo->text().isEmpty() && ui->lineSintomas->text().isEmpty())
    {
        QMessageBox::warning(this, tr("ERROR INFO"), tr("Campos Incompletos\n Por favor llene todos loc campos"),
                             QMessageBox::Ok);
    }else
    {
        QString motivo,sintomas,fecha,h_inicio,h_fin,idPaciente;
        motivo = ui->lineMotivo->text();
        sintomas = ui->lineSintomas->text();
        fecha = ui->dateFecha->date().toString("yyyy-MM-dd");

        QModelIndex index = ui->listHorasDisponibles->currentIndex();
        h_inicio = index.data(Qt::DisplayRole).toString();

        qDebug() << h_inicio;

        QSqlQuery buscaIDPaciente(mDatabase);
        buscaIDPaciente.prepare("select id_paciente from paciente as p "
                                "inner join persona as per on p.id_persona=per.id_persona "
                                "where per.nombre='"+idUsuarioPaciente+"';");
        buscaIDPaciente.exec();
        while(buscaIDPaciente.next())
        {
            idPaciente=buscaIDPaciente.value(0).toString();
        }

        QMessageBox::StandardButton Confirmacion;
        Confirmacion = QMessageBox::question(this, "ADVERTENCIA", "¿Está seguro de realizar esta reservación?",
                                             QMessageBox::Yes | QMessageBox::No);

        if(Confirmacion == QMessageBox::Yes)
        {
            QSqlQuery InsertaCita(mDatabase);
            InsertaCita.prepare("insert into cita_medica(motivo,descripcion,fecha,h_inicio,id_medico,id_paciente) "
                                "values('"+motivo+"','"+sintomas+"','"+fecha+"','"+h_inicio+"','"+idMedico+"','"+idPaciente+"')");
            InsertaCita.exec();

            QMessageBox::Information(this, tr("Registrar Cita"),tr("Cita Registrada Correctamente"),
                                          QMessageBox::Ok);
        }

        this->close();

    }
}


void paciente_crear_cita::llenarLista()
{
    QStringList listaHoras;
    horas->setStringList(listaHoras);
    QSet<QTime> setHoras;

    QTime horaInicio(9,0,0), horaFin(17,0,0);
    for(QTime hora = horaInicio; hora < horaFin; hora  = hora.addSecs(3600))
    {
       setHoras.insert(hora);
    }

    QList<QTime> listTime = setHoras.toList();

    std::sort(listTime.begin(), listTime.end());

    for(auto &f : listTime)
    {
        listaHoras << f.toString("hh:mm 'hrs.'");
    }

    horas->setStringList(listaHoras);
}

void paciente_crear_cita::on_ButtonBuscaHorario_clicked()
{
    QList<QString> horasCitadas;
    QString dia = ui->dateFecha->date().toString("yyyy-MM-dd");

    QSqlQuery buscaHora(mDatabase);
    buscaHora.prepare("select hora_inicio, hora_fin from cita_medica where id_medico="+idMedico+" && fecha='"+dia+"'");
    buscaHora.exec();

    QString inicio, final;
    while(buscaHora.next())
    {
       inicio = buscaHora.value(0).toString();
       horasCitadas.push_back(inicio);
    }

    llenarLista();
}
