#include "administrador_tarjeta_servicios.h"
#include "ui_administrador_tarjeta_servicios.h"

administrador_tarjeta_servicios::administrador_tarjeta_servicios(QString id, QString servicio, QString foto, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::administrador_tarjeta_servicios)
{
    ui->setupUi(this);
    ui->lbl_servicio->setText(servicio);
    QPixmap img(foto);
    ui->img->setPixmap(img);
}

administrador_tarjeta_servicios::~administrador_tarjeta_servicios()
{
    delete ui;
}

void administrador_tarjeta_servicios::on_btn_gestionar_clicked()
{

}
