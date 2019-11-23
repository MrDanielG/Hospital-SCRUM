#include "remedios_caseros.h"
#include "ui_remedios_caseros.h"

remedios_caseros::remedios_caseros(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::remedios_caseros)
{
    ui->setupUi(this);
}

remedios_caseros::~remedios_caseros()
{
    delete ui;
}
