#ifndef TARJETA_DOCTOR_H
#define TARJETA_DOCTOR_H

#include <QWidget>
#include "Clases/doctor.h"

namespace Ui {
class tarjeta_doctor;
}

class tarjeta_doctor : public QWidget
{
    Q_OBJECT

public:
    explicit tarjeta_doctor(QString foto, QString nombre, QString especialidad, int estrellas, QWidget *parent = nullptr);
    ~tarjeta_doctor();

private slots:


    void on_btn_visualizar_clicked();

private:
    Ui::tarjeta_doctor *ui;
    QString nombre, especialidad, foto;
    int estrellas;
};

#endif // TARJETA_DOCTOR_H
