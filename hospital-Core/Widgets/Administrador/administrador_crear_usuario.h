#ifndef ADMINISTRADOR_CREAR_USUARIO_H
#define ADMINISTRADOR_CREAR_USUARIO_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
namespace Ui {
class administrador_crear_usuario;
}

class administrador_crear_usuario : public QDialog
{
    Q_OBJECT

public:
    explicit administrador_crear_usuario(QWidget *parent = nullptr);
    ~administrador_crear_usuario();

private slots:
    void on_btn_continuar_clicked();

    void on_btn_crear_usuario_clicked();

private:
    Ui::administrador_crear_usuario *ui;
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
    QString edad;
    QString foto;
    QString direccion;
};

#endif // ADMINISTRADOR_CREAR_USUARIO_H
