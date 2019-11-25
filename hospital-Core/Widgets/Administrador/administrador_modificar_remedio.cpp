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

        QMessageBox::information(this, tr("Actualizar"),
                     tr("Se actualizo correctamente el remedio"));
        this->close();
    } else {
        QMessageBox::information(this, tr("Actualizar"),
                     tr("No se Actualizo el remedio"));
        this->close();
    }
}

void administrador_modificar_remedio::on_btn_foto_clicked()
{
    QString dir = QFileDialog::getOpenFileName(this,tr("Seleccione una imagen"), "/C:/", tr("Archivos de Imagen (* .png,* .jpg)"));
    qDebug()<<dir << "/directorio";
    if(!dir.isEmpty()){
        this->foto = dir;
        QMessageBox::information(this, tr("Correcto"),
                     tr("Imagen agregada correctamente"));
        ui->foto->setPixmap(dir);
    }else{
        QMessageBox::information(this, tr("Error"),
                     tr("No se actualizo la imagen"));
    }
}
