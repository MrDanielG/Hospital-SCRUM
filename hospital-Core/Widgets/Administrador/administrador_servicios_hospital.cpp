#include "administrador_servicios_hospital.h"
#include "ui_administrador_servicios_hospital.h"

administrador_servicios_hospital::administrador_servicios_hospital(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::administrador_servicios_hospital)
{
    ui->setupUi(this);
}

administrador_servicios_hospital::~administrador_servicios_hospital()
{
    delete ui;
}
