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
    explicit tarjeta_doctor(QString foto, QString nombre, QString especialidad, int estrellas, QWidget *parent = nullptr);
    ~tarjeta_doctor();
    void insertarDatos();

private slots:


    void on_btn_visualizar_clicked();

private:
    Ui::tarjeta_doctor *ui;
    QSqlDatabase mDatabase;
    QString nombre, especialidad, foto, id;
    int estrellas;
};

#endif // TARJETA_DOCTOR_H
