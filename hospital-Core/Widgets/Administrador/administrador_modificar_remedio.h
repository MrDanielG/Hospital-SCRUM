#ifndef ADMINISTRADOR_MODIFICAR_REMEDIO_H
#define ADMINISTRADOR_MODIFICAR_REMEDIO_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFileDialog>
namespace Ui {
class administrador_modificar_remedio;
}

class administrador_modificar_remedio : public QDialog
{
    Q_OBJECT

public:
    explicit administrador_modificar_remedio(QString, QString, QString, QString, QWidget *parent = nullptr);
    ~administrador_modificar_remedio();

private slots:
    void on_btn_actualizar_clicked();

    void on_btn_foto_clicked();

private:
    Ui::administrador_modificar_remedio *ui;
    QSqlDatabase mDatabase;
    QString id;
    QString nombre;
    QString descripcion;
    QString foto;
};

#endif // ADMINISTRADOR_MODIFICAR_REMEDIO_H
