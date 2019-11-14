#include "farmaceutico_realizarventas.h"
#include "ui_farmaceutico_realizarventas.h"

farmaceutico_realizarVentas::farmaceutico_realizarVentas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::farmaceutico_realizarVentas)
{
    ui->setupUi(this);

}

farmaceutico_realizarVentas::~farmaceutico_realizarVentas()
{
    delete ui;
}
