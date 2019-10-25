#include "iniciar_sesion.h"
#include "ui_iniciar_sesion.h"

iniciar_sesion::iniciar_sesion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::iniciar_sesion)
{
    ui->setupUi(this);
}

iniciar_sesion::~iniciar_sesion()
{
    delete ui;
}
