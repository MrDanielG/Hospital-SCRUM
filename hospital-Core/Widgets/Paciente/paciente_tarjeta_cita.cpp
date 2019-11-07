#include "paciente_tarjeta_cita.h"
#include "ui_paciente_tarjeta_cita.h"

paciente_tarjeta_cita::paciente_tarjeta_cita(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::paciente_tarjeta_cita)
{
    ui->setupUi(this);
}

paciente_tarjeta_cita::~paciente_tarjeta_cita()
{
    delete ui;
}
