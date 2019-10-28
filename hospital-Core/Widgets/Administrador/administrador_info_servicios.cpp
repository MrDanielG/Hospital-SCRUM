#include "administrador_info_servicios.h"
#include "ui_administrador_info_servicios.h"

administrador_info_servicios::administrador_info_servicios(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administrador_info_servicios)
{
    ui->setupUi(this);
}

administrador_info_servicios::~administrador_info_servicios()
{
    delete ui;
}
