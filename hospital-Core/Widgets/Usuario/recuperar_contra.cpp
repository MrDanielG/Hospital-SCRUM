#include "recuperar_contra.h"
#include "ui_recuperar_contra.h"

recuperar_contra::recuperar_contra(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::recuperar_contra)
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
        qDebug() << "ERROR con Base de Datos, esto es: ADMINISTRADOR CREAR USUARIOS";
        return;
    }
    else
    {
        qDebug() << "Base de datos continua abierta, esto es: ADMINISTRADOR CREAR USUARIOS";
    }

    ui->stackedWidget->setCurrentIndex(0);

}

recuperar_contra::~recuperar_contra(){
    delete ui;
}

void recuperar_contra::on_btn_continuar_clicked()
{
    if(ui->line_curp->text() != ""){
        curpob = ui->line_curp->text();
        QSqlQuery buscarcurp(mDatabase);
        buscarcurp.prepare("select id_usuario from persona where curp = '"+curpob+"'");
        buscarcurp.exec();

        if(buscarcurp.next()){
             userid = buscarcurp.value(0).toString();
             ui->stackedWidget->setCurrentIndex(1);
        }else{
            QMessageBox::warning(this, tr("Error"),tr("No exite"),
                                                      QMessageBox::Ok);
        }


    }else{
        QMessageBox::warning(this, tr("Error"),tr("El campo no puede estar vacio"),
                                                  QMessageBox::Ok);
    }
}






void recuperar_contra::on_btn_enviar_clicked()
{
    if(ui->line_curp->text() != ""){
        QString word = ui->line_palabra->text();
        QSqlQuery buscarpalabra(mDatabase);
        buscarpalabra.prepare("select mascota, id_usuario, contrasenia from usuario where id_usuario = '"+userid+"'");
        buscarpalabra.exec();

        if(buscarpalabra.next()){
            QString wo = buscarpalabra.value(0).toString();
            id_us = buscarpalabra.value(1).toString();
            pass = buscarpalabra.value(2).toString();

            if(word == wo){
                ui->stackedWidget->setCurrentIndex(2);
                ui->line_nombre_usuario->setText(id_us);
                ui->line_contrasenia->setText(pass);
            }else{
                QMessageBox::warning(this, tr("Error"),tr("La palabra no coincide"),
                                                          QMessageBox::Ok);
            }
        }
    }else{
        QMessageBox::warning(this, tr("Error"),tr("El campo no puede estar vacio"),
                                                  QMessageBox::Ok);
    }
}

void recuperar_contra::on_btn_hecho_clicked()
{
    this->close();
}
