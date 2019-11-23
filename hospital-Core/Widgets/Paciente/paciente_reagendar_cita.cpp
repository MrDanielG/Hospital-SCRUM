#include "paciente_reagendar_cita.h"
#include "ui_paciente_reagendar_cita.h"

paciente_Reagendar_cita::paciente_Reagendar_cita(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::paciente_Reagendar_cita)
{
    ui->setupUi(this);
    this->bandera=false;
}

paciente_Reagendar_cita::~paciente_Reagendar_cita()
{
    delete ui;
}

bool paciente_Reagendar_cita::getBand()
{
    return  this->bandera;
}
void paciente_Reagendar_cita::on_btn_reagendar_SI_clicked()
{
    this->bandera=true;
    this->close();
}

void paciente_Reagendar_cita::on_btn_reagendar_NO_clicked()
{
    this->bandera=false;
    this->close();
}
