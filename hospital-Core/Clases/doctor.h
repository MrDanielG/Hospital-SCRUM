#ifndef DOCTOR_H
#define DOCTOR_H

#include <QString>

class Doctor{
private:
    QString nombre, fotografia, especialidad;
    int estrellas;

public:
    Doctor();
    Doctor(QString, QString, QString, int);
};

#endif // DOCTOR_H
