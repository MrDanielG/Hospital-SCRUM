#ifndef USUARIO_H
#define USUARIO_H

#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include "Widgets/Usuario/inicar_sesion.h"

class Usuario{
private:
    QSqlDatabase mDatabase;
    QString nombre_usuario;
    QString passwd;
    QString tipo_usuario;

public:
    Usuario();
    Usuario(QString, QString);
    bool validarNombreU(QString);
    bool validarContrasenia(QString,QString);
//    void crearUsuarioBD();
//    void modificarUsuarioBD();
//    void modificarContraBD();
    friend class iniciar_sesion;

};

#endif // USUARIO_H
