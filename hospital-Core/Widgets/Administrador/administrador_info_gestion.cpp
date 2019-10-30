#include "administrador_info_gestion.h"
#include "ui_administrador_info_gestion.h"
#include "QDebug"
#include "QMessageBox"
administrador_info_gestion::administrador_info_gestion(QString nombre, QString tipo_usr, QString info1, QString info2, QString info3, QString img, QString id_usuario, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administrador_info_gestion)
{
    ui->setupUi(this);
    mDatabase = QSqlDatabase::database("Connection");
    if(!mDatabase.isOpen()){
          qDebug()<<"Error Base de Datos, esto es: ADMINISTRADOR INFO GESTION";
           return;
    }else{
            qDebug()<<"Base de datos continua abierta, esto es: ADMINISTRADOR INFO GESTION";
    }

    this->nombre = nombre;
    this->tipo_usr = tipo_usr;
    this->info1 = info1;
    this->info2 = info2;
    this->info3 = info3;
    this->id_usr = id_usuario;

    QPixmap imagen(img);
    ui->img->setPixmap(imagen);
    ui->lbl_nombre->setText(this->nombre);
    ui->lbl_tipo_usuario->setText(this->tipo_usr);
    ui->lbl_info1->setText(this->info1);
    ui->lbl_info2->setText(this->info2);
    ui->lbl_info3->setText(this->info3);
}

administrador_info_gestion::~administrador_info_gestion()
{
    delete ui;
}

void administrador_info_gestion::on_btn_eliminar_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Eliminar Usuarios");
    msgBox.setText("¿Desea eliminar este Usuario?");
    msgBox.setInformativeText("Esta accion no podra ser revertida");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);

    if(msgBox.exec() == QMessageBox::Yes){
        QString idUsuario = this->id_usr;

        //Elimina Primero la Persona
        QSqlQuery eliminaPersona(mDatabase);
        eliminaPersona.prepare("DELETE FROM persona WHERE persona.id_usuario = '"+idUsuario+"'");
        eliminaPersona.exec();

        //Elimina Usuario
        QSqlQuery eliminaUsuario(mDatabase);
        eliminaUsuario.prepare("DELETE FROM usuario WHERE usuario.id_usuario = '"+idUsuario+"'");
        eliminaUsuario.exec();

        QMessageBox::information(this, tr("Exito"),
                                       tr("El Usuario ha sido Eliminado"),
                                       QMessageBox::Ok);
        this->close();
    }else {
      // No elimina
    }
}
