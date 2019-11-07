#ifndef ADMINISTRADOR_VISUALIZAR_CANCELACION_CITA_H
#define ADMINISTRADOR_VISUALIZAR_CANCELACION_CITA_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class administrador_visualizar_cancelacion_cita;
}

class administrador_visualizar_cancelacion_cita : public QDialog
{
    Q_OBJECT

public:
    explicit administrador_visualizar_cancelacion_cita(QString idMedico, QString motivo, QString cita, QString hInicio, QString hFin, QWidget *parent = nullptr);
    ~administrador_visualizar_cancelacion_cita();
    void insertarDatos();
private slots:

    void on_pbtn_cancelarRechazo_clicked();

    void on_pbtn_aprobarRechazo_clicked();

private:
    Ui::administrador_visualizar_cancelacion_cita *ui;
    QSqlDatabase mDatabase;
    QString idMedico, motivo, cita, hInicio, hFin;
};

#endif // ADMINISTRADOR_VISUALIZAR_CANCELACION_CITA_H
