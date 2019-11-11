#include "recepcionista_tarjeta_operaciones.h"
#include "ui_recepcionista_tarjeta_operaciones.h"

recepcionista_tarjeta_operaciones::recepcionista_tarjeta_operaciones(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::recepcionista_tarjeta_operaciones)
{
    ui->setupUi(this);
}

recepcionista_tarjeta_operaciones::~recepcionista_tarjeta_operaciones()
{
    delete ui;
}
