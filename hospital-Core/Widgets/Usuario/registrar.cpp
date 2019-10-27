#include "registrar.h"
#include "ui_registrar.h"

registrar::registrar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registrar)
{
    ui->setupUi(this);
}

registrar::~registrar()
{
    delete ui;
}
