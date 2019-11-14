#include "farmaceutico_tarjeta_medicamento_venta.h"
#include "ui_farmaceutico_tarjeta_medicamento_venta.h"

farmaceutico_tarjeta_medicamento_venta::farmaceutico_tarjeta_medicamento_venta(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::farmaceutico_tarjeta_medicamento_venta)
{
    ui->setupUi(this);
}

farmaceutico_tarjeta_medicamento_venta::~farmaceutico_tarjeta_medicamento_venta()
{
    delete ui;
}
