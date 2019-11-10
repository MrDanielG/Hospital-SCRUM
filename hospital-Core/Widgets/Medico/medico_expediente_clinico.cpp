#include "medico_expediente_clinico.h"
#include "ui_medico_expediente_clinico.h"

medico_expediente_clinico::medico_expediente_clinico(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::medico_expediente_clinico)
{
    ui->setupUi(this);
}

medico_expediente_clinico::~medico_expediente_clinico()
{
    delete ui;
}
