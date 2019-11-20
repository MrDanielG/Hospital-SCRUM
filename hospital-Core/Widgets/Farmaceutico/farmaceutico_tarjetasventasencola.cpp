#include "farmaceutico_tarjetasventasencola.h"
#include "ui_farmaceutico_tarjetasventasencola.h"
#include <Widgets/Farmaceutico/farmaceutico_realizarventas.h>

farmaceutico_tarjetasventasencola::farmaceutico_tarjetasventasencola(farmaceutico_realizarVentas *parent) :
    QWidget(parent),
    ui(new Ui::farmaceutico_tarjetasventasencola)
{
    ui->setupUi(this);
    this->padre = parent;
}

farmaceutico_tarjetasventasencola::~farmaceutico_tarjetasventasencola()
{
    delete ui;
}

void farmaceutico_tarjetasventasencola::insertarDatos(QString nombre, QString precio)
{
    this->nombre = nombre;
    this->precio = precio;
    setDatos();
}

void farmaceutico_tarjetasventasencola::setDatos()
{
    ui->Nombre->setText(nombre);
    ui->Cantidad->setValue(1);
}


void farmaceutico_tarjetasventasencola::on_Cantidad_valueChanged(int arg1)
{

    this->can = arg1;
    ui->Cantidad->setValue(can);
    float prec = precio.toFloat();
    float total = can * prec;
    Total += total;
    ui->Total->setText(QString::number(total));

    this->padre->insertarTotal(Total);

    qDebug()<<"Estetotal "<<Total;

}





