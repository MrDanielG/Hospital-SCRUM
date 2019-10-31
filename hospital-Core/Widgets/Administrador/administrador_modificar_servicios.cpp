#include "administrador_modificar_servicios.h"
#include "ui_administrador_modificar_servicios.h"
#include "QDebug"
#include "QMessageBox"
administrador_modificar_servicios::administrador_modificar_servicios(QString id_servicio, QString nombre, QString info, QString foto, QWidget *parent) :
    QDialog(parent),
     ui(new Ui::administrador_modificar_servicios)
{
    ui->setupUi(this);
    mDatabase = QSqlDatabase::database("Connection");
    if (!mDatabase.isOpen())
    {
        qDebug() << "ERROR con Base de Datos, esto es: MODIFICAR USUARIOS";
        return;
    }
    else
    {
        qDebug() << "Base de datos continua abierta, esto es: MODIFICAR USUARIOS";
    }
    this->id_servicio = id_servicio;
    //Se agrega la info a la UI
    ui->nombre_servicio->setText(nombre);
    ui->info_servicio->setPlainText(info);
    QPixmap img(foto);
    ui->img->setPixmap(img);
}

administrador_modificar_servicios::~administrador_modificar_servicios()
{
    delete ui;
}

void administrador_modificar_servicios::on_btn_modificar_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Actualizar Servicio");
    msgBox.setText("¿Desea Actualizar este Servicio?");
    msgBox.setInformativeText("Esta accion no podra ser revertida");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);

    if(msgBox.exec() == QMessageBox::Yes){
        this->nombre = ui->nombre_servicio->text();
        this->info = ui->info_servicio->toPlainText();
        this->foto = "C:/img/imgServicio1.png"; //Momentanea en lo que se agrega funcionalidad a la img
        QSqlQuery query(mDatabase);
        query.prepare("UPDATE `info` SET `nombre`='"+this->nombre+"',`descripcion`='"+this->info+"',`imagen`='"+this->foto+"' WHERE id_info = '"+this->id_servicio+"'");
        query.exec();

        QMessageBox::information(this, tr("Actualizacion"),tr("Usuario Actualizado."),
                                      QMessageBox::Ok);
        this->close();
    } else {
        QMessageBox::information(this, tr("Actualizacion"),tr("Usuario NO Actualizado."),
                                      QMessageBox::Ok);
    }
}
