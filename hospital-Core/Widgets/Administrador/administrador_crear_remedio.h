#ifndef ADMINISTRADOR_CREAR_REMEDIO_H
#define ADMINISTRADOR_CREAR_REMEDIO_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFileDialog>
namespace Ui {
class administrador_crear_remedio;
}

class administrador_crear_remedio : public QDialog
{
    Q_OBJECT

public:
    explicit administrador_crear_remedio(QWidget *parent = nullptr);
    ~administrador_crear_remedio();

private slots:
    void on_btn_crear_clicked();

    void on_btn_foto_clicked();

private:
    Ui::administrador_crear_remedio *ui;
    QSqlDatabase mDatabase;
    QString nombre;
    QString descripcion;
    QString foto = "C:/img/imgTipTest.png"; //Img por defecto
};

#endif // ADMINISTRADOR_CREAR_REMEDIO_H
