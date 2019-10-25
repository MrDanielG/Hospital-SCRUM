#include "inicar_sesion.h"
#include "ui_inicar_sesion.h"

inicar_sesion::inicar_sesion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inicar_sesion)
{
    ui->setupUi(this);
}

inicar_sesion::~inicar_sesion()
{
    delete ui;
}
