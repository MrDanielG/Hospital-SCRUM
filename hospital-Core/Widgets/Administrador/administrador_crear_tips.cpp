#include "administrador_crear_tips.h"
#include "ui_administrador_crear_tips.h"

administrador_crear_tips::administrador_crear_tips(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administrador_crear_tips)
{
    ui->setupUi(this);
}

administrador_crear_tips::~administrador_crear_tips()
{
    delete ui;
}
