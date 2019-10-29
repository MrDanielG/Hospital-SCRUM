#include "tarjeta_servicios.h"
#include "ui_tarjeta_servicios.h"

Tarjeta_Servicios::Tarjeta_Servicios(QString foto, QString nombre, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tarjeta_Servicios){
    ui->setupUi(this);

    this->foto = foto;
    this->nombre = nombre;
}

Tarjeta_Servicios::~Tarjeta_Servicios()
{
    delete ui;
}

void Tarjeta_Servicios::insertarDatos(){
    QPixmap imag(this->foto);
    ui->img_servicios->setPixmap(imag.scaled(141,111, Qt::IgnoreAspectRatio));
    ui->nombre_servicio->setText(this->nombre);

}
