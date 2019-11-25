#include "medico_solicitudes.h"
#include "ui_medico_solicitudes.h"
#include "Widgets/Medico/tarjeta_permiso.h"

medico_solicitudes::medico_solicitudes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::medico_solicitudes)
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
        qDebug() << "ERROR";
    }else{
        qDebug() << "base de datos sigue conectada en Solicitudes_Permisos";
    }

    ui->label_foto->hide();
    ui->label_11->hide();
    ui->lbl_nombre->hide();
    ui->label_9->hide();
    ui->date_fecha_Inicio->hide();
    ui->label_12->hide();
    ui->date_fecha_Fin->hide();
    ui->label_13->hide();
    ui->txt_motivo->hide();
    ui->btn_solicitar_permiso->hide();

}

medico_solicitudes::~medico_solicitudes()
{
    delete ui;
}

void medico_solicitudes::setIdEmpleado(QString idEmpleado)
{
    this->idEmpleado=idEmpleado;
}

void medico_solicitudes::setIdPersona(QString idPersona)
{
    this->idPersona=idPersona;
}

void medico_solicitudes::setUsuario(QString usuario)
{
    this->usuario=usuario;
}

QString medico_solicitudes::getUsuario()
{
    return this->usuario;
}

void medico_solicitudes::limpiarCatalogo()
{
    while (QLayoutItem *item = ui->gridLayout->takeAt(0))
    {
        Q_ASSERT(!item->layout()); // otherwise the layout will leak
        delete item->widget();
        delete item;
    }
}

void medico_solicitudes::on_btn_solicitudesEspera_clicked()
{

    QSqlQuery query(mDatabase),query2(mDatabase);
    query.prepare("SELECT * FROM permiso WHERE id_empleado="+this->idEmpleado+" && aprobado=1;");
    query.exec();

    limpiarCatalogo();

    int i = 0;
    int row = 0;
    int col = 0;

    while(query.next())
    {
        QString idPermiso = query.value(0).toString();
        QString f_inicio = query.value(2).toString();
        QString f_fin = query.value(3).toString();

        query2.prepare("SELECT foto FROM persona WHERE id_persona="+this->idPersona);
        query2.exec();
        query2.next();


        QString foto = query2.value(0).toString();

        row = i / 2;
        col = i % 2;

        tarjeta_permiso *tarjeta=new tarjeta_permiso(idPermiso,foto,f_inicio,f_fin);

        i++;
        ui->gridLayout->addWidget(tarjeta, row, col);
    }

}

void medico_solicitudes::on_btn_solicitudesRechazadas_clicked()
{
    QSqlQuery query(mDatabase),query2(mDatabase);
    query.prepare("SELECT * FROM permiso WHERE id_empleado="+this->idEmpleado+" && aprobado=3;");
    query.exec();

    limpiarCatalogo();

    int i = 0;
    int row = 0;
    int col = 0;

    while(query.next())
    {
        QString idPermiso = query.value(0).toString();
        QString f_inicio = query.value(2).toString();
        QString f_fin = query.value(3).toString();

        query2.prepare("SELECT foto FROM persona WHERE id_persona="+this->idPersona);
        query2.exec();
        query2.next();


        QString foto = query2.value(0).toString();

        row = i / 2;
        col = i % 2;

        tarjeta_permiso *tarjeta=new tarjeta_permiso(idPermiso,foto,f_inicio,f_fin);

        i++;
        ui->gridLayout->addWidget(tarjeta, row, col);
    }
}

void medico_solicitudes::on_btn_solicitudesAprobadas_clicked()
{
    QSqlQuery query(mDatabase),query2(mDatabase);
    query.prepare("SELECT * FROM permiso WHERE id_empleado="+this->idEmpleado+" && aprobado=2;");
    query.exec();

    limpiarCatalogo();

    int i = 0;
    int row = 0;
    int col = 0;

    while(query.next())
    {
        QString idPermiso = query.value(0).toString();
        QString f_inicio = query.value(2).toString();
        QString f_fin = query.value(3).toString();

        query2.prepare("SELECT foto FROM persona WHERE id_persona="+this->idPersona);
        query2.exec();
        query2.next();


        QString foto = query2.value(0).toString();

        row = i / 2;
        col = i % 2;

        tarjeta_permiso *tarjeta=new tarjeta_permiso(idPermiso,foto,f_inicio,f_fin);

        i++;
        ui->gridLayout->addWidget(tarjeta, row, col);
    }
}

void medico_solicitudes::inicializar()
{
    on_btn_solicitudesEspera_clicked();
}

void medico_solicitudes::on_comboPermiso_activated(const QString &arg1)
{
    if(arg1=="--Tipo de Permiso--")
    {
        ui->label_foto->hide();
        ui->label_11->hide();
        ui->lbl_nombre->hide();
        ui->label_9->hide();
        ui->date_fecha_Inicio->hide();
        ui->label_12->hide();
        ui->date_fecha_Fin->hide();
        ui->label_13->hide();
        ui->txt_motivo->hide();
        ui->btn_solicitar_permiso->hide();

    }else
    {
        if(arg1=="Baja Temporal")
        {
            ui->label_foto->show();
            ui->label_11->show();
            ui->lbl_nombre->show();
            ui->label_9->show();
            ui->date_fecha_Inicio->show();
            ui->label_12->show();
            ui->date_fecha_Fin->show();
            ui->date_fecha_Fin->setEnabled(true);
            ui->label_13->show();
            ui->txt_motivo->show();
            ui->btn_solicitar_permiso->show();
        }else
        {
            if(arg1=="Baja Definitiva")
            {
                ui->label_foto->show();
                ui->label_11->show();
                ui->lbl_nombre->show();
                ui->label_9->show();
                ui->date_fecha_Inicio->show();
                ui->date_fecha_Fin->setEnabled(false);
                ui->label_13->show();
                ui->btn_solicitar_permiso->show();
                ui->txt_motivo->show();
            }
        }
    }
}
