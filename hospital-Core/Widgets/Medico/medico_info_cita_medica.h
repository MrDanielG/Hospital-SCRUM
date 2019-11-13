#ifndef MEDICO_INFO_CITA_MEDICA_H
#define MEDICO_INFO_CITA_MEDICA_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>


namespace Ui {
class medico_info_cita_medica;
}

class medico_info_cita_medica : public QWidget
{
    Q_OBJECT

public:
    explicit medico_info_cita_medica(QString nombre, QString paterno, QString materno,QString hInicio, QString hFin, QString foto,QString idCita, QWidget *parent = nullptr);
    ~medico_info_cita_medica();
    void insertarDatos();

private slots:
    void on_btn_rechazar_cita_clicked();

    void on_btn_iniciar_cita_clicked();

private:
    Ui::medico_info_cita_medica *ui;
    QSqlDatabase mDatabase;
    QString nombre,paterno,materno,idCita,hInicio,hFin,foto,descripcion;
};

#endif // MEDICO_INFO_CITA_MEDICA_H
