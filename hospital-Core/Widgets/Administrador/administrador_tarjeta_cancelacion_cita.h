#ifndef ADMINISTRADOR_TARJETA_CANCELACION_CITA_H
#define ADMINISTRADOR_TARJETA_CANCELACION_CITA_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class administrador_tarjeta_cancelacion_cita;
}

class administrador_tarjeta_cancelacion_cita : public QWidget
{
    Q_OBJECT

public:
    explicit administrador_tarjeta_cancelacion_cita(QString nombre, QString paterno, QString materno, QString motivo, QString hInicio, QString hFin, QString foto, QWidget *parent = nullptr);
    ~administrador_tarjeta_cancelacion_cita();
    void insertarDatos();

private slots:
    void on_btn_admin_visualizar_cancelacion_cita_clicked();

private:
    Ui::administrador_tarjeta_cancelacion_cita *ui;
    QSqlDatabase mDatabase;
    QString nombre, paterno, materno, motivo, hInicio, hFin, foto;
};

#endif // ADMINISTRADOR_TARJETA_CANCELACION_CITA_H
