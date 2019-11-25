#include "administrador_modificar_remedio.h"
#include "ui_administrador_modificar_remedio.h"

administrador_modificar_remedio::administrador_modificar_remedio(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administrador_modificar_remedio)
{
    ui->setupUi(this);
}

administrador_modificar_remedio::~administrador_modificar_remedio()
{
    delete ui;
}
