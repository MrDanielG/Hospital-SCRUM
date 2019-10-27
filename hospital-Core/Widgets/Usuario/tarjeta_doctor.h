#ifndef TARJETA_DOCTOR_H
#define TARJETA_DOCTOR_H

#include <QWidget>

namespace Ui {
class tarjeta_doctor;
}

class tarjeta_doctor : public QWidget
{
    Q_OBJECT

public:
    explicit tarjeta_doctor(QWidget *parent = nullptr);
    ~tarjeta_doctor();

private:
    Ui::tarjeta_doctor *ui;
};

#endif // TARJETA_DOCTOR_H
