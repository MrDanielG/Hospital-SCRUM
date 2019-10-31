#include "administrador_modificar_servicios.h"
#include "ui_administrador_modificar_servicios.h"

administrador_modificar_servicios::administrador_modificar_servicios(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administrador_modificar_servicios)
{
    ui->setupUi(this);
}

administrador_modificar_servicios::~administrador_modificar_servicios()
{
    delete ui;
}
