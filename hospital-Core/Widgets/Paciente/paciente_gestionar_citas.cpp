#include "paciente_gestionar_citas.h"
#include "ui_paciente_gestionar_citas.h"

paciente_gestionar_citas::paciente_gestionar_citas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::paciente_gestionar_citas)
{
    ui->setupUi(this);
}

paciente_gestionar_citas::~paciente_gestionar_citas()
{
    delete ui;
}
