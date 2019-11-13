#include "recepcion_tarjeta_citas.h"
#include "ui_recepcion_tarjeta_citas.h"

recepcion_tarjeta_citas::recepcion_tarjeta_citas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::recepcion_tarjeta_citas)
{
    ui->setupUi(this);
}

recepcion_tarjeta_citas::~recepcion_tarjeta_citas()
{
    delete ui;
}

void recepcion_tarjeta_citas::insertarDatos(QString fecha, QString hora, QString nombre, QString paterno){
    ui->fecha->setText(fecha);
    ui->hora->setText(hora);
    ui->doctor->setText(nombre);
    ui->paterno->setText(paterno);

}
