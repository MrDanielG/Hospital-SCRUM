#include "administrador_crear_remedio.h"
#include "ui_administrador_crear_remedio.h"

administrador_crear_remedio::administrador_crear_remedio(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administrador_crear_remedio)
{
    ui->setupUi(this);
}

administrador_crear_remedio::~administrador_crear_remedio()
{
    delete ui;
}
