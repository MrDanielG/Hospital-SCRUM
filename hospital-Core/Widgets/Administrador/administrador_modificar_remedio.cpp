#include "administrador_modificar_remedio.h"
#include "ui_administrador_modificar_remedio.h"
#include "QPixmap"
#include "QMessageBox"
#include "QDebug"
administrador_modificar_remedio::administrador_modificar_remedio(QString id, QString nombre, QString descripcion, QString foto, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administrador_modificar_remedio)
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
        qDebug() << "ERROR en MODIFICAR REMEDIOS";
    }else{
        qDebug() << "base de datos sigue conectada en MODIFICAR REMEDIOS";
    }

    this->id = id;
    this->nombre = nombre;
    this-> descripcion = descripcion;
    this->foto = foto;

    ui->foto->setPixmap(foto);
    ui->nombreRemedio->setText(nombre);
    ui->descripcion->setPlainText(descripcion);
}

administrador_modificar_remedio::~administrador_modificar_remedio()
{
    delete ui;
}

void administrador_modificar_remedio::on_btn_actualizar_clicked()
{
    QMessageBox msgBox(QMessageBox::Question,"Actualizar","¿Desea Actualizar éste Remedio?",QMessageBox::Yes|QMessageBox::No);
    msgBox.setButtonText(QMessageBox::Yes,"Sí");
    msgBox.setButtonText(QMessageBox::No,"No");

    if(msgBox.exec()==QMessageBox::Yes){

        this->nombre = ui->nombreRemedio->text();
        this->descripcion = ui->descripcion->toPlainText();

        QSqlQuery query(mDatabase);
        query.exec("UPDATE `info` SET `nombre`='"+this->nombre+"',`descripcion`='"+this->descripcion+"',`imagen`='"+this->foto+"' WHERE id_info = '"+this->id+"'");

        QMessageBox msgBox(QMessageBox::Warning,tr("Actualizacion"), tr("Remedio Actualizado"), QMessageBox::Yes);
        msgBox.setButtonText(QMessageBox::Yes, tr("Entendido"));
        msgBox.exec();
        this->close();
    } else {
        QMessageBox msgBox(QMessageBox::Warning,tr("Actualizacion"), tr("Remedio NO Actualizado"), QMessageBox::Yes);
        msgBox.setButtonText(QMessageBox::Yes, tr("Entendido"));
        msgBox.exec();
        this->close();
    }
}

void administrador_modificar_remedio::on_btn_foto_clicked()
{
    QString dir = QFileDialog::getOpenFileName(this,tr("Seleccione una imagen"), "/C:/", tr("Archivos de Imagen (* .png,* .jpg)"));
    qDebug()<<dir << "/directorio";
    if(!dir.isEmpty()){
        this->foto = dir;
        QMessageBox msgBox(QMessageBox::Warning,tr("Imagen"), tr("Imagen Agregada Correctamente"), QMessageBox::Yes);
        msgBox.setButtonText(QMessageBox::Yes, tr("Entendido"));
        msgBox.exec();
        ui->foto->setPixmap(dir);
    }else{
        QMessageBox msgBox(QMessageBox::Warning,tr("Imagen"), tr("Imagen NO Agregada"), QMessageBox::Yes);
        msgBox.setButtonText(QMessageBox::Yes, tr("Entendido"));
        msgBox.exec();
    }
}
