#ifndef ADMINISTRADOR_TARJETA_JUSTIFICACION_STAF_H
#define ADMINISTRADOR_TARJETA_JUSTIFICACION_STAF_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>


namespace Ui {
class administrador_tarjeta_justificacion_staf;
}

class administrador_tarjeta_justificacion_staf : public QWidget
{
    Q_OBJECT

public:
    explicit administrador_tarjeta_justificacion_staf(QString id, QString descripcion, QString fecha_inicio, QString fecha_fin, QString nombre, QString foto, QString tipo, QWidget *parent = nullptr);
    ~administrador_tarjeta_justificacion_staf();
    void insertarDatos();

private slots:
    void on_visualizar_justificacion_pbtn_clicked();

private:
    Ui::administrador_tarjeta_justificacion_staf *ui;
    QSqlDatabase mDatabase;
    QString id, descripcion, fecha_inicio, fecha_fin, nombre, foto, tipo;
};

#endif // ADMINISTRADOR_TARJETA_JUSTIFICACION_STAF_H
