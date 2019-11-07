#include "paciente_crear_cita.h"
#include "ui_paciente_crear_cita.h"

paciente_crear_cita::paciente_crear_cita(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::paciente_crear_cita)
{
    ui->setupUi(this);
}

paciente_crear_cita::~paciente_crear_cita()
{
    delete ui;
}
