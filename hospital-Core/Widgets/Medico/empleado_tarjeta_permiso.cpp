#include "empleado_tarjeta_permiso.h"
#include "ui_empleado_tarjeta_permiso.h"

empleado_tarjeta_permiso::empleado_tarjeta_permiso(QString idPermiso,QString foto,QString f_inicio,QString f_fin,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::empleado_tarjeta_permiso)
{
    ui->setupUi(this);
    this->idPermiso=idPermiso;
    this->foto=foto;
    this->f_inicio=f_inicio;
    this->f_fin=f_fin;

    QPixmap imag(this->foto);
    ui->foto->setPixmap(imag);
    ui->lbl_fecha_inicio->setText(this->f_inicio);
    ui->lbl_fecha_fin->setText(this->f_fin);
}

empleado_tarjeta_permiso::~empleado_tarjeta_permiso()
{
    delete ui;
}
