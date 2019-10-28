#include "tarjeta_doctor.h"
#include "ui_tarjeta_doctor.h"

tarjeta_doctor::tarjeta_doctor(QString foto, QString nombre, QString especialidad, QString estrellas, QWidget *parent) : QWidget(parent),
    ui(new Ui::tarjeta_doctor)
{
    ui->setupUi(this);
}

tarjeta_doctor::~tarjeta_doctor()
{
    delete ui;
}
