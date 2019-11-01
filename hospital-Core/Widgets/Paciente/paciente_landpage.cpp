#include "paciente_landpage.h"
#include "ui_paciente_landpage.h"

paciente_landpage::paciente_landpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::paciente_landpage)
{
    ui->setupUi(this);
}

paciente_landpage::~paciente_landpage()
{
    delete ui;
}
