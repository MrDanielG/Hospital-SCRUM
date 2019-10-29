#include "usuario.h"
#include <QDebug>
#include <QSqlQuery>
#include <QMessageBox>

Usuario::Usuario(){

    mDatabase = QSqlDatabase::database("Connection");
    if (!mDatabase.isOpen()){
        qDebug() << "ERROR";
    }else{
        qDebug() << "base de datos sigue conectada en USUARIO";
    }

}

Usuario::Usuario(QString nu, QString pd){

    mDatabase = QSqlDatabase::database("Connection");
    if (!mDatabase.isOpen()){
        qDebug() << "ERROR";
    }else{
        qDebug() << "base de datos sigue conectada en USUARIO C2";
    }

    nombre_usuario = nu;
    passwd = pd;
    tipo_usuario = "3";
}

bool Usuario::validarNombreU(QString nu){
    bool existe = false;

    QSqlQuery buscarNombre(mDatabase);
    buscarNombre.prepare("select id_usuario from usuario where id_usuario ='"+nu+"'");
    buscarNombre.exec();

    while(buscarNombre.next()){
        qDebug() << "si encuentra el  nombre";
        QString nombretemporal = buscarNombre.value(0).toString();
        qDebug() << "si encuentra el ";
        if(nombretemporal == nu){
           existe = true;
           qDebug() << "Su nombre de usuario es correcto";
        }else{
           existe = false;
           qDebug() << "Nombre de usuario INCORRECTO";
        }
    }

    return existe;
}

bool Usuario::validarContrasenia(QString nu,QString pd){
    qDebug() << "Si valida contraseña";
    bool existe = false;
    QSqlQuery buscarContra(mDatabase);
    buscarContra.exec("select contrasenia from usuario where id_usuario = '"+nu+"' ");
    while(buscarContra.next()){
        QString contratemporal = buscarContra.value(0).toString();
        if(contratemporal == pd){
            existe = true;
            qDebug() << "Su contraseña es correcta";
        }else{
            existe = false;
            qDebug() << "Su contraseña es INCORRECTA";
        }
    }
    buscarContra.finish();
    return existe;
}


//void Usuario::crearUsuarioBD(){
//    QSqlQuery nuevo(mDatabase);
//    nuevo.exec("insert into usuario(id_usuario,contra_usuario,id_tipo_usuario) values('"+nombre_usuario+"','"+passwd+"',3)");
//    qDebug() << "Usuario insertado";
//    nuevo.finish();
//}

//void Usuario::modificarUsuarioBD(){
//    QSqlQuery modificar(mDatabase);
//    modificar.exec("SET SQL_SAFE_UPDATES='0'; update usuario set id_usuario = '"+nombre_usuario+"' where contra_usuario = '"+passwd+"'; SET SQL_SAFE_UPDATES='1';");
//    qDebug() << "Usuario modificado correctamente";
//    modificar.finish();
//}

//void Usuario::modificarContraBD(){
//    QSqlQuery modificarContrasenia(mDatabase);
//    modificarContrasenia.exec("update usuario set contra_usuario = '"+passwd+"' where id_usuario = '"+nombre_usuario+"' ");
//    modificarContrasenia.finish();
//}
