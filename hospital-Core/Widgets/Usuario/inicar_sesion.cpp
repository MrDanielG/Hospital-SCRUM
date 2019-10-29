#include "inicar_sesion.h"
#include "ui_inicar_sesion.h"
#include <QDebug>
#include <QMessageBox>
#include "Clases/usuario.h"
#include "mainwindow.h"

inicar_sesion::inicar_sesion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inicar_sesion)
{
    ui->setupUi(this);
    mDatabase = QSqlDatabase::database("Connection");
    if (!mDatabase.isOpen()){
        qDebug() << "ERROR";
    }else{
        qDebug() << "base de datos sigue conectada en INICIAR SESION";
    }
}

inicar_sesion::~inicar_sesion()
{
    delete ui;
}

int inicar_sesion::getindex()
{
    return this->tipodeusuario;
}

void inicar_sesion::on_btn_iniciarsesion_sesion_clicked(){
    QString nombre_usuario;
    QString contrasenia;
    QString tipo_usuario = " ";

    nombre_usuario = ui->line_correo->text();
    contrasenia = ui->line_contrasenia->text();

    if(nombre_usuario.isEmpty()|| contrasenia.isEmpty()){
        QMessageBox::warning(this,"Datos incompletos", "Ingresa tu usuario y contraseña");
    }else{

        Usuario usuario(nombre_usuario,contrasenia);
        //Primero se valida que exista el nombre de usuario

        if(usuario.validarNombreU(nombre_usuario) == true){
            if(usuario.validarContrasenia(nombre_usuario, contrasenia) == true){
                    qDebug()<<"Prequery";
                    QSqlQuery buscartipo(mDatabase);
                    buscartipo.exec("select id_tipo_usuario from usuario where contrasenia = '"+usuario.passwd+"' and id_usuario = '"+usuario.nombre_usuario+"' ");

                    while(buscartipo.next()){
                        QString id_tp;
                        id_tp = buscartipo.value(0).toString();

                        //Ahora de acuerdo al id de TipoUsuario vamos a ver qué nombre de tipo de usuario es
                        QSqlQuery tipo(mDatabase);
                        tipo.exec("select nombre_tipo from tipo_usuario where id_tipo_usuario = '"+id_tp+"' ");

                        while(tipo.next()){
                            tipo_usuario = tipo.value(0).toString();
                            usuario.tipo_usuario = tipo_usuario;

                            if(usuario.tipo_usuario == "Administrador"){
                                ui->line_correo->clear();
                                ui->line_contrasenia->clear();

                                this->tipodeusuario = 3;
                                qDebug()<<"Tipo Usuariooooo "<<this->tipodeusuario;
                                //MainWindow *main = new MainWindow(this, this->tipodeusuario);
                                this->close();
                            }
                        }
                        tipo.finish();
                    }
                    buscartipo.finish();
                //}
            }else{
                QMessageBox::warning(this,"Contraseña incorrecta","Tu contraseña es incorrecta, intenta nuevamente");
                ui->line_correo->clear();
                ui->line_contrasenia->clear();
            }
        }else{
            QMessageBox::warning(this,"Usuario incorrecto","El nombre de usuario que has ingresado es incorrecto o no existe, te invitamos a registrarte");
            ui->line_correo->clear();
            ui->line_contrasenia->clear();
        }
    }

}
