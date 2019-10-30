#ifndef TARJETA_DOCTOR_H
#define TARJETA_DOCTOR_H

#include <QWidget>
#include "Clases/doctor.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class tarjeta_doctor;
}

class tarjeta_doctor : public QWidget
{
    Q_OBJECT

public:
    explicit tarjeta_doctor(QString idpersona, QString idmedico, QString nombre, QString paterno, QString materno, QString calificacion, QString foto, QString especialidad, QWidget *parent = nullptr);
    ~tarjeta_doctor();
    void insertarDatos();

private slots:
    void on_btn_visualizar_clicked();

private:
    Ui::tarjeta_doctor *ui;
    QSqlDatabase mDatabase;
    QString nombre, especialidad, foto, idpersona, idmedico, paterno, materno, calificacion;
};

#endif // TARJETA_DOCTOR_H
