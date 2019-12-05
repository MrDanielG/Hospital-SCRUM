#include "tarjeta_permiso.h"
#include "ui_tarjeta_permiso.h"

tarjeta_permiso::tarjeta_permiso(QString idPermiso,QString foto,QString f_inicio,QString f_fin,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tarjeta_permiso)
{
    ui->setupUi(this);
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

tarjeta_permiso::~tarjeta_permiso()
{
    delete ui;
}
