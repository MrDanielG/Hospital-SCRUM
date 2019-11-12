#include "medico_tarjeta_cita.h"
#include "ui_medico_tarjeta_cita.h"

medico_tarjeta_cita::medico_tarjeta_cita(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::medico_tarjeta_cita)
{
    ui->setupUi(this);
}

medico_tarjeta_cita::~medico_tarjeta_cita()
{
    delete ui;
}
