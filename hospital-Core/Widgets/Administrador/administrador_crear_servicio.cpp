#include "administrador_crear_servicio.h"
#include "ui_administrador_crear_servicio.h"
#include "QDebug"
#include "QMessageBox"
#include <QFileDialog>
administrador_crear_servicio::administrador_crear_servicio(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administrador_crear_servicio)
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
    if (!mDatabase.isOpen())
    {
        qDebug() << "ERROR con Base de Datos, esto es: MODIFICAR USUARIOS";
        return;
    }
    else
    {
        qDebug() << "Base de datos continua abierta, esto es: MODIFICAR USUARIOS";
    }
}

administrador_crear_servicio::~administrador_crear_servicio()
{
    delete ui;
}

void administrador_crear_servicio::on_btn_crear_clicked()
{
    QMessageBox msgBox(QMessageBox::Warning,tr("Crear Servico"), tr("Desea Crear un nuevo Servicio"), QMessageBox::Yes | QMessageBox::No);
    msgBox.setButtonText(QMessageBox::Yes, tr("Si"));
    msgBox.exec();

    if(msgBox.exec() == QMessageBox::Yes){
        this->nombre = ui->nombre_servicio->text();
        this->info = ui->info_servicio->toPlainText();

        QSqlQuery query(mDatabase);
        query.prepare("INSERT INTO `info`(`nombre`, `descripcion`, `id_tipo_info`, `imagen`, id_administrador) VALUES ('"+this->nombre+"','"+this->info+"',3,'"+this->foto+"',2)");
        query.exec();

        QMessageBox::information(this, tr("Crear Servicio"),tr("Servicio Correctamente Creado."),
                                      QMessageBox::Ok);
        this->close();
    }
}

void administrador_crear_servicio::on_btn_foto_clicked()
{
    QString dir = QFileDialog::getOpenFileName(this,tr("Seleccione una imagen"), "/C:/", tr("Archivos de Imagen (* .png,* .jpg)"));
    qDebug()<<dir << "/directorio";
    if(!dir.isEmpty()){
        this->foto = dir;
        QMessageBox msgBox(QMessageBox::Warning,tr("Imagen"), tr("Imagen Agregada Correctamente"), QMessageBox::Yes);
        msgBox.setButtonText(QMessageBox::Yes, tr("Entendido"));
        msgBox.exec();
        ui->img->setPixmap(dir);
    }else{
        QMessageBox msgBox(QMessageBox::Warning,tr("Imagen"), tr("Imagen NO Agregada"), QMessageBox::Yes);
        msgBox.setButtonText(QMessageBox::Yes, tr("Entendido"));
        msgBox.exec();
    }
}
