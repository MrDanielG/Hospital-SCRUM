#ifndef ADMINISTRADOR_MODIFICAR_USUARIO_H
#define ADMINISTRADOR_MODIFICAR_USUARIO_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class administrador_modificar_usuario;
}

class administrador_modificar_usuario : public QDialog
{
    Q_OBJECT

public:
    explicit administrador_modificar_usuario(QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QWidget *parent = nullptr);
    ~administrador_modificar_usuario();

private slots:
    void on_btn_continuar_clicked();
    void on_btn_crear_usuario_clicked();

    void on_btn_foto_clicked();

private:
    Ui::administrador_modificar_usuario *ui;
    QSqlDatabase mDatabase;
    QString nombreUsuario;
    QString tipoUsuario;
    QString contra;
    QString nombre;
    QString paterno;
    QString materno;
    QString nacimiento;
    QString correo;
    QString sexo;
    QString foto;
    QString direccion;
    QString curp;
    QString mascota;
};

#endif // ADMINISTRADOR_MODIFICAR_USUARIO_H
