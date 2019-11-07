#ifndef INICAR_SESION_H
#define INICAR_SESION_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>

class Usuario;
namespace Ui {
class inicar_sesion;
}

class inicar_sesion : public QDialog
{
    Q_OBJECT

public:
    explicit inicar_sesion(QWidget *parent = nullptr);
    explicit inicar_sesion(Usuario *, QWidget *parent = nullptr);
    ~inicar_sesion();
    int getindex();
    QString getUsuario();

    Usuario *returnUsuario();
private slots:
    void on_btn_iniciarsesion_sesion_clicked();
    void on_btn_contrasegnaolvidada_clicked();

private:
    Ui::inicar_sesion *ui;
    QSqlDatabase mDatabase;
    int tipodeusuario;
    QString usuario;
    Usuario *usuarioDatos;
};

#endif // INICAR_SESION_H
