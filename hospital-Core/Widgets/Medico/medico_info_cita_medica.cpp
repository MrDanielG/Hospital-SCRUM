#include "medico_info_cita_medica.h"
#include "ui_medico_info_cita_medica.h"
#include "Widgets/Medico/medico_rechazar_cita_medica.h"
#include "medico_expediente_clinico.h"

medico_info_cita_medica::medico_info_cita_medica(QString nombre, QString paterno, QString materno,QString hInicio, QString hFin, QString foto,QString idCita,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::medico_info_cita_medica)
{
    ui->setupUi(this);
    setWindowTitle("Información cita médica");
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
          qDebug()<<"Error Base de Datos, esto es: MEDICO INFO CITA MEDICA";
           return;
    }else{
            qDebug()<<"Base de datos continua abierta, esto es:  MEDICO INFO CITA MEDICA";
    }

    this->nombre=nombre;
    this->paterno=paterno;
    this->materno=materno;
    this->hInicio=hInicio;
    this->hFin=hFin;
    this->foto=foto;
    this->idCita=idCita;

    QSqlQuery query(mDatabase);
    query.prepare("select descripcion from cita_medica where id_cita_medica='"+this->idCita+"'" );
    query.exec();
    query.next();

    this->descripcion=query.value(0).toString();

    insertarDatos();


}

medico_info_cita_medica::~medico_info_cita_medica()
{
    delete ui;
}

void medico_info_cita_medica::insertarDatos()
{
    QString nombreCompleto = this->nombre+" "+this->paterno+" "+this->materno;
    QString horario = this->hInicio+" - "+this->hFin;
    QPixmap imag(this->foto);

    ui->lbl_nombre->setText(nombreCompleto);
    ui->lbl_foto->setPixmap(imag);
    ui->lbl_horario->setText(horario);
    ui->lbl_descripcion->setPlainText(descripcion);
}


void medico_info_cita_medica::on_btn_rechazar_cita_clicked()
{
    qDebug()<<"idCita" <<this->idCita;
    medico_rechazar_cita_medica rechazarCita(this->idCita);
    rechazarCita.exec();

    if(rechazarCita.getBandera())
    {
        rechazarCita.setBandera();
        this->close();
    }

}

void medico_info_cita_medica::on_btn_iniciar_cita_clicked()
{
    medico_expediente_clinico *expediente=new medico_expediente_clinico(this->nombre,this->paterno,this->materno,this->foto,this->idCita);
    expediente->show();
}
