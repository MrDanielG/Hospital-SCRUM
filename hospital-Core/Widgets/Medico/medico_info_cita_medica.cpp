#include "medico_info_cita_medica.h"
#include "ui_medico_info_cita_medica.h"

medico_info_cita_medica::medico_info_cita_medica(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::medico_info_cita_medica)
{
    ui->setupUi(this);
}

medico_info_cita_medica::~medico_info_cita_medica()
{
    delete ui;
}
