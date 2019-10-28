#include "administrador_tarjeta_gestion.h"
#include "ui_administrador_tarjeta_gestion.h"

administrador_tarjeta_gestion::administrador_tarjeta_gestion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::administrador_tarjeta_gestion)
{
    ui->setupUi(this);
}

administrador_tarjeta_gestion::~administrador_tarjeta_gestion()
{
    delete ui;
}
