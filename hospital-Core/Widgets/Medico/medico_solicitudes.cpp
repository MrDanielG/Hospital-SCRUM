#include "medico_solicitudes.h"
#include "ui_medico_solicitudes.h"
#include "Widgets/Medico/tarjeta_permiso.h"
#include <QDate>
#include "QMessageBox"

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
    ui->date_fecha_Inicio->setDate(QDate::currentDate());
    ui->date_fecha_Inicio->setMinimumDate(QDate::currentDate());
    ui->label_12->hide();
    ui->date_fecha_Fin->hide();
    ui->date_fecha_Fin->setDate(QDate::currentDate());
     ui->date_fecha_Fin->setMinimumDate(QDate::currentDate().addDays(1));
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
    QSqlQuery query(mDatabase);
    query.prepare("SELECT nombre, paterno, materno,foto FROM persona WHERE id_persona="+this->idPersona);
    query.exec();
    query.next();
    ui->lbl_nombre->setText(query.value(0).toString()+" "+query.value(1).toString()+" "+query.value(2).toString());
    QPixmap imag(query.value(3).toString());
    ui->label_foto->setPixmap(imag);

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
                ui->label_12->show();
                ui->date_fecha_Fin->show();
                ui->date_fecha_Fin->setEnabled(false);
                ui->label_13->show();
                ui->btn_solicitar_permiso->show();
                ui->txt_motivo->show();
            }
        }
    }
}

void medico_solicitudes::on_btn_solicitar_permiso_clicked()
{
    QSqlQuery query(mDatabase);
    QString descripcion=ui->txt_motivo->toPlainText();
    QString fecha_inicio=ui->date_fecha_Inicio->date().toString("yyyy-MM-dd");
    QString fecha_fin=ui->date_fecha_Fin->date().toString("yyyy-MM-dd");

    QMessageBox info;

    if(descripcion!="")
    {
        QMessageBox msgBox(QMessageBox::Question,"ADVERTENCIA","¿Estas seguro de solicitar este permiso?",QMessageBox::Yes|QMessageBox::No);
                           msgBox.setButtonText(QMessageBox::Yes,"Sí");
                           msgBox.setButtonText(QMessageBox::No,"No");

        if(msgBox.exec()==QMessageBox::Yes)
        {
            if(ui->comboPermiso->currentText()=="Baja Temporal")
            {
                query.prepare("INSERT INTO permiso (descripcion, fecha_inicio,fecha_fin, aprobado, id_empleado) VALUES ('"+descripcion+"', '"+fecha_inicio+"','"+fecha_fin+"', '1', '"+this->idEmpleado+"');");
                query.exec();

            }else{
                if(ui->comboPermiso->currentText()=="Baja Definitiva")
                {
                    query.prepare("INSERT INTO permiso (descripcion, fecha_inicio, aprobado, id_empleado) VALUES ('"+descripcion+"', '"+fecha_inicio+"', '1', '"+this->idEmpleado+"');");
                    query.exec();
                }
            }
            info.setWindowTitle("Información");
            info.setText("Permiso solicitado con éxito, espera la respuesta del administrador.");
            info.setStandardButtons(QMessageBox::Ok);
            info.setDefaultButton(QMessageBox::Ok);
            info.setButtonText(QMessageBox::Ok,"Aceptar");
            info.exec();

         }
    }else
    {
        info.setWindowTitle("Información");
        info.setText("Debes escribir el motivo por el cual pediras tu permiso.");
        info.setStandardButtons(QMessageBox::Ok);
        info.setDefaultButton(QMessageBox::Ok);
        info.setButtonText(QMessageBox::Ok,"Aceptar");
        info.exec();
    }


    ui->txt_motivo->clear();
    inicializar();

}
