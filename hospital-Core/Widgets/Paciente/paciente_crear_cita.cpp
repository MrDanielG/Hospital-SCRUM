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

    if(usuario=="reagendar")
    {
        ui->btn_agendarCita->setVisible(false);
        this->idCita=idM;
        QSqlQuery query(mDatabase);
        query.prepare("SELECT * FROM cita_medica WHERE id_cita_medica="+this->idCita);
        query.exec();
        query.next();

        this->idMedico=query.value(6).toString();
        this->idUsuarioPaciente=query.value(7).toString();
        QSqlQuery nombre(mDatabase);
        qDebug() << idMedico;
        nombre.prepare("select concat(p.nombre,' ',p.paterno,' ',p.materno) as Nombre from persona as p "
                       "inner join empleado as e on p.id_persona=e.id_persona "
                       "inner join medico as m on e.id_empleado=m.id_empleado "
                       "where m.id_medico='"+idMedico+"';");
        nombre.exec();
        nombre.next();

        ui->dateFecha->setMinimumDate(QDate::currentDate().addDays(1));
        ui->label_NomMedico->setText(nombre.value(0).toString());
        ui->lineMotivo->setText(query.value(1).toString());
        ui->dateFecha->setDate(query.value(3).toDate());
        ui->lineSintomas->setText(query.value(2).toString());

    }else
    {
        ui->btn_reagendar_cita->setVisible(false);

        this->idUsuarioPaciente = usuario;
        this->idMedico = idM;

         ui->dateFecha->setMinimumDate(QDate::currentDate().addDays(1));

        //Para mostrar el nombre del médico que eligió cuando reserva su cita
        QSqlQuery nombre(mDatabase);
        qDebug() << idMedico;
        nombre.prepare("select concat(p.nombre,' ',p.paterno,' ',p.materno) as Nombre from persona as p "
                       "inner join empleado as e on p.id_persona=e.id_persona "
                       "inner join medico as m on e.id_empleado=m.id_empleado "
                       "where m.id_medico='"+idMedico+"';");
        nombre.exec();
        QString nom;
        while(nombre.next())
        {
            nom = nombre.value(0).toString();
        }

        ui->label_NomMedico->setText(nom);
    }
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
        QString fecha = ui->dateEdit->date().toString("yyyy/MM/dd");
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

    }*/

    if(ui->lineMotivo->text().isEmpty() && ui->lineSintomas->text().isEmpty())
    {
        QMessageBox::warning(this, tr("ERROR INFO"), tr("Campos Incompletos\n Por favor llene todos los campos"),
                             QMessageBox::Ok);
    }else
    {
        QString motivo,sintomas,fecha,inicio,fin,idPaciente;
        QTime h_inicio,h_fin;
        motivo = ui->lineMotivo->text();
        sintomas = ui->lineSintomas->text();
        fecha = ui->dateFecha->date().toString("yyyy-MM-dd");
        inicio = ui->horasDisponibles->currentIndex().data().toString();
        h_inicio = QTime::fromString(inicio,"hh:mm 'hrs'");

        fin = ui->horasDisponibles->currentIndex().data().toString();
        h_fin = QTime::fromString(inicio,"hh:mm 'hrs'");
        h_fin = h_fin.addSecs(3600);
        /*inicio = h_inicio.toString("hh:mm");
        h_fin = h_inicio.addSecs(3600);
        fin = h_fin.toString("hh:mm");
*/
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
        Confirmacion = QMessageBox::question(this, "ADVERTENCIA", "¿Está seguro de agendar esta cita?",
                                             QMessageBox::Yes | QMessageBox::No);

        if(Confirmacion == QMessageBox::Yes)
        {
            QSqlQuery InsertaCita(mDatabase);
            InsertaCita.prepare("insert into cita_medica(motivo,descripcion,fecha,hora_inicio,hora_fin,id_medico,id_paciente,estado,calificacion) "
                                "values('"+motivo+"','"+sintomas+"','"+fecha+"','"+h_inicio.toString("HH:mm:ss")+"','"+h_fin.toString("HH:mm:ss")+"','"+idMedico+"','"+idPaciente+"',1,0)");
            InsertaCita.exec();

            QMessageBox::information(this, tr("Registrar Cita"),tr("Cita Registrada Correctamente"),
                                          QMessageBox::Ok);
        }

        this->close();

    }
}


void paciente_crear_cita::on_ButtonBuscaHorario_clicked()
{
    ui->horasDisponibles->clear();
        QStringList listaHoras;
        QTime horaInicio(9,0,0), horaFin(17,0,0);
        for(QTime hora = horaInicio; hora < horaFin; hora  = hora.addSecs(3600))
        {
            listaHoras.push_back(hora.toString("hh:mm 'hrs'"));
        }

        QList<QString> horasCitadas;
        QString dia = ui->dateFecha->date().toString("yyyy-MM-dd");

        QSqlQuery buscaHora(mDatabase);
        buscaHora.prepare("select hora_inicio from cita_medica where id_medico="+idMedico+" && fecha='"+dia+"';");
        buscaHora.exec();

        QString inicio;
        while(buscaHora.next())
        {
            inicio = buscaHora.value(0).toTime().toString("hh:mm 'hrs'");
            horasCitadas.push_back(inicio);
            qDebug() << inicio;
        }

        QString aux1, aux2;
        foreach (aux1, listaHoras) {
            foreach(aux2, horasCitadas){
                if(aux1 == aux2){
                    listaHoras.removeOne(aux1);
                }
            }
        }

        ui->horasDisponibles->addItems(listaHoras);
}

void paciente_crear_cita::on_btn_reagendar_cita_clicked()
{
    if(ui->lineMotivo->text().isEmpty() && ui->lineSintomas->text().isEmpty())
    {
        QMessageBox::warning(this, tr("ERROR INFO"), tr("Campos Incompletos\n Por favor llene todos los campos"),
                             QMessageBox::Ok);
    }else
    {
        QString motivo,sintomas,fecha,inicio,fin,idPaciente;
        QTime h_inicio,h_fin;
        motivo = ui->lineMotivo->text();
        sintomas = ui->lineSintomas->text();
        fecha = ui->dateFecha->date().toString("yyyy-MM-dd");
        inicio = ui->horasDisponibles->currentIndex().data().toString();
        h_inicio = QTime::fromString(inicio,"hh:mm 'hrs'");

        fin = ui->horasDisponibles->currentIndex().data().toString();
        h_fin = QTime::fromString(inicio,"hh:mm 'hrs'");
        h_fin = h_fin.addSecs(3600);
        /*inicio = h_inicio.toString("hh:mm");
        h_fin = h_inicio.addSecs(3600);
        fin = h_fin.toString("hh:mm");
*/

        QMessageBox::StandardButton Confirmacion;
        Confirmacion = QMessageBox::question(this, "ADVERTENCIA", "¿Está seguro de reagendar esta cita?",
                                             QMessageBox::Yes | QMessageBox::No);

        if(Confirmacion == QMessageBox::Yes)
        {
            QSqlQuery InsertaCita(mDatabase);
            InsertaCita.prepare("UPDATE cita_medica SET motivo='"+motivo+"',descripcion='"+sintomas+"',fecha='"+fecha+"',hora_inicio='"+h_inicio.toString("HH:mm:ss")+"',hora_fin='"+h_fin.toString("HH:mm:ss")+"' WHERE id_cita_medica="+this->idCita);
            InsertaCita.exec();

            QMessageBox::information(this, tr("Reagendar Cita"),tr("Cita agendada con éxito"),
                                          QMessageBox::Ok);
        }

        this->close();
      }
}
