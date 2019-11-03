#include "medico_rechazar_cita_medica.h"
#include "ui_medico_rechazar_cita_medica.h"

medico_rechazar_cita_medica::medico_rechazar_cita_medica(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::medico_rechazar_cita_medica)
{
    ui->setupUi(this);
}

medico_rechazar_cita_medica::~medico_rechazar_cita_medica()
{
    delete ui;
}
