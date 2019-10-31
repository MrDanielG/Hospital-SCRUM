#ifndef REGISTRAR_H
#define REGISTRAR_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class registrar;
}

class registrar : public QDialog
{
    Q_OBJECT

public:
    explicit registrar(QWidget *parent = nullptr);
    ~registrar();

private slots:
    void on_btn_continuar_clicked();

    void on_btn_crear_usuario_clicked();

private:
    Ui::registrar *ui;
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
    QString curp;
    QString foto;
    QString direccion;
};

#endif // REGISTRAR_H
