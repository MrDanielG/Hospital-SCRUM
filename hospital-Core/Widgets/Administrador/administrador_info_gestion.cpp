#include "administrador_info_gestion.h"
#include "ui_administrador_info_gestion.h"

administrador_info_gestion::administrador_info_gestion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administrador_info_gestion)
{
    ui->setupUi(this);
}

administrador_info_gestion::~administrador_info_gestion()
{
    delete ui;
}
