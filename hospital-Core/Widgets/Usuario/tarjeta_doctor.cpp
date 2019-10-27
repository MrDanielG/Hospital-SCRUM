#include "tarjeta_doctor.h"
#include "ui_tarjeta_doctor.h"

tarjeta_doctor::tarjeta_doctor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tarjeta_doctor)
{
    ui->setupUi(this);
}

tarjeta_doctor::~tarjeta_doctor()
{
    delete ui;
}
