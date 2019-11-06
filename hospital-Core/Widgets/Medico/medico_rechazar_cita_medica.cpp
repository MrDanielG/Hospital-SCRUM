#include "medico_rechazar_cita_medica.h"
#include "ui_medico_rechazar_cita_medica.h"
#include "qmessagebox.h"
#include "QDateTime"

medico_rechazar_cita_medica::medico_rechazar_cita_medica(QString idCita, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::medico_rechazar_cita_medica)
{
    ui->setupUi(this);
    setWindowTitle("Rechazo de cita");
    this->idCita=idCita;
    this->bandera=false;

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
          qDebug()<<"Error Base de Datos, esto es: MEDICO RECHAZAR CITA MEDICA";
           return;
    }else{
            qDebug()<<"Base de datos continua abierta, esto es:  MEDICO RECHAZAR CITA MEDICA";
    }

}

medico_rechazar_cita_medica::~medico_rechazar_cita_medica()
{
    delete ui;
}

void medico_rechazar_cita_medica::on_btn_cancelar_rechazo_cita_clicked()
{
    this->close();
}

bool medico_rechazar_cita_medica::getBandera()
{
    return this->bandera;
}

void medico_rechazar_cita_medica::setBandera()
{
    this->bandera=false;
}

void medico_rechazar_cita_medica::on_btn_Rechazar_cita_clicked()
{

    QMessageBox info;
    QString hr,min,sec,auxh,hr2;
    QString justificacion= ui->justificacion->toPlainText();
    QTime hora= QTime::currentTime(),hcita,hdif;
    hr=QString::number( hora.hour()-12);
    min=QString::number(hora.minute());
    sec=QString::number(hora.second());
    QString horaActual=hr+":"+min+":"+sec;

    qDebug()<<"Hora "<<horaActual;

    QSqlQuery query(mDatabase);
    QSqlQuery query2(mDatabase);
    query.prepare("select hora_inicio from cita_medica where id_cita_medica='"+this->idCita+"'");
    query.exec();
    query.next();
    hcita=query.value(0).toTime();
    auxh=query.value(0).toString();
    qDebug()<<"hcita "<<hcita;
    qDebug()<<"auxh "<<auxh;

    query.prepare("select timediff('"+auxh+"','"+horaActual+"')");
    query.exec();
    query.next();
    hdif=query.value(0).toTime();
    hr2=QString::number( hdif.hour());



    if(justificacion!="")
    {
        if(hr2.toInt()>=3)
        {
           QMessageBox msgBox(QMessageBox::Question,"Confimacion","¿Estas seguro de rechazar esta consulta?",QMessageBox::Yes|QMessageBox::No);
           msgBox.setButtonText(QMessageBox::Yes,"Sí");
           msgBox.setButtonText(QMessageBox::No,"No");

            if(msgBox.exec()==QMessageBox::Yes){
                query2.prepare("update cita_medica set estado=2, justificacion_rechazo='"+justificacion+"' where id_cita_medica="+this->idCita);
                query2.exec();
                qDebug()<<"dif horas "<<hr2;
                qDebug()<<"idCita "<<this->idCita;

                bandera=true;

                info.setWindowTitle("Información");
                info.setText("Tu solicitud de rechazo fue enviada con éxito, espera la autorización del administrador.");
                info.setStandardButtons(QMessageBox::Ok);
                info.setDefaultButton(QMessageBox::Ok);
                info.setButtonText(QMessageBox::Ok,"Aceptar");
                info.exec();

                this->close();


            }


        }else
        {
            info.setWindowTitle("Información");
            info.setText("No puedes rechazar esta cita, solo se puede rechazar citas con más de 3 hrs de anticipación.");
            info.setStandardButtons(QMessageBox::Ok);
            info.setDefaultButton(QMessageBox::Ok);
            info.setButtonText(QMessageBox::Ok,"Aceptar");
            info.exec();
        }
    }else
    {
        info.setWindowTitle("Información");
        info.setText("Debe haber una justificación para rechazar la cita.");
        info.setStandardButtons(QMessageBox::Ok);
        info.setDefaultButton(QMessageBox::Ok);
        info.setButtonText(QMessageBox::Ok,"Aceptar");
        info.exec();
    }
}
