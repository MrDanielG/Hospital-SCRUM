#include "recepcionista_agregar_internado.h"
#include "ui_recepcionista_agregar_internado.h"

recepcionista_agregar_internado::recepcionista_agregar_internado(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::recepcionista_agregar_internado)
{
    ui->setupUi(this);
}

recepcionista_agregar_internado::~recepcionista_agregar_internado()
{
    delete ui;
}
