#ifndef ADMINISTRADOR_CREAR_SERVICIO_H
#define ADMINISTRADOR_CREAR_SERVICIO_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
namespace Ui {
class administrador_crear_servicio;
}

class administrador_crear_servicio : public QDialog
{
    Q_OBJECT

public:
    explicit administrador_crear_servicio(QWidget *parent = nullptr);
    ~administrador_crear_servicio();

private slots:
    void on_btn_crear_clicked();

    void on_btn_foto_clicked();

private:
    Ui::administrador_crear_servicio *ui;
    QSqlDatabase mDatabase;
    QString id_servicio, nombre, info, foto = "C:/img/imgServicio1.png";
};

#endif // ADMINISTRADOR_CREAR_SERVICIO_H
