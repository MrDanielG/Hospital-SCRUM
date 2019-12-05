#include "administrador_info_servicios.h"
#include "ui_administrador_info_servicios.h"
#include "Widgets/Administrador/administrador_modificar_servicios.h"
#include "QDebug"
#include "QMessageBox"
administrador_info_servicios::administrador_info_servicios(QString id, QString servicio, QString info, QString foto, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administrador_info_servicios)
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
          qDebug()<<"Error Base de Datos, esto es: ADMINISTRADOR INFO SERVICIOS";
           return;
    }else{
            qDebug()<<"Base de datos continua abierta, esto es: ADMINISTRADOR INFO SERVICIOS";
    }

    this->id = id;
    this->servicio = servicio;
    this->info = info;
    this->foto = foto;

    //Se insertan los valores a la UI
    ui->nombre_servicio->setText(servicio);
    ui->info_servicio->setPlainText(info);
    QPixmap img(foto);
    ui->img->setPixmap(img);
}

administrador_info_servicios::~administrador_info_servicios()
{
    delete ui;
}

void administrador_info_servicios::on_btn_modificar_clicked()
{
    administrador_modificar_servicios modificarServicios(this->id, this->servicio, this->info, this->foto);
    modificarServicios.exec();
    this->close();
}


void administrador_info_servicios::on_btn_eliminar_clicked()
{
    QMessageBox messageBox(QMessageBox::Warning,tr("Eliminar Servicio"), tr("Estás seguro de dar de baja éste servico?"), QMessageBox::Yes | QMessageBox::No);
    messageBox.setButtonText(QMessageBox::Yes, tr("Sí"));
    messageBox.setButtonText(QMessageBox::No, tr("No"));

    if (messageBox.exec() == QMessageBox::Yes){
        QSqlQuery query(mDatabase);
        query.prepare("delete from info where id_info = "+this->id);
        query.exec();

        QMessageBox messageBox2(QMessageBox::Warning,tr("Eliminacion"), tr("El servicio ha sido eliminado"), QMessageBox::Yes);
        messageBox2.setButtonText(QMessageBox::Yes, tr("Entendido"));
        messageBox2.exec();


        this->close();
    } else {
        QMessageBox messageBox2(QMessageBox::Warning,tr("No se elimino"), tr("El servicio NO ha sido eliminado"), QMessageBox::Yes);
        messageBox2.setButtonText(QMessageBox::Yes, tr("Entendido"));
        messageBox2.exec();
        this->close();
    }
}
