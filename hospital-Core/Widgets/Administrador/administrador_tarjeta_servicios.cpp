#include "administrador_tarjeta_servicios.h"
#include "ui_administrador_tarjeta_servicios.h"

administrador_tarjeta_servicios::administrador_tarjeta_servicios(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::administrador_tarjeta_servicios)
{
    ui->setupUi(this);
}

administrador_tarjeta_servicios::~administrador_tarjeta_servicios()
{
    delete ui;
}
