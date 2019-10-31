#include "administrador_crear_servicio.h"
#include "ui_administrador_crear_servicio.h"
#include "QDebug"
#include "QMessageBox"
administrador_crear_servicio::administrador_crear_servicio(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administrador_crear_servicio)
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
}

administrador_crear_servicio::~administrador_crear_servicio()
{
    delete ui;
}

void administrador_crear_servicio::on_btn_crear_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Crear Servicio");
    msgBox.setText("¿Desea Crear este Servicio?");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);

    if(msgBox.exec() == QMessageBox::Yes){
        this->nombre = ui->nombre_servicio->text();
        this->info = ui->info_servicio->toPlainText();
        this->foto = "C:/img/imgServicio1.png"; //Momentanea en lo que se agrega funcionalidad a la img

        QSqlQuery query(mDatabase);
        query.prepare("INSERT INTO `info`(`nombre`, `descripcion`, `id_tipo_info`, `imagen`, id_administrador) VALUES ('"+this->nombre+"','"+this->info+"',3,'"+this->foto+"',1)");
        query.exec();

        QMessageBox::information(this, tr("Crear Servicio"),tr("Servicio Correctamente Creado."),
                                      QMessageBox::Ok);
        this->close();
    }
}
