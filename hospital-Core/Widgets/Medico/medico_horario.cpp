#include "medico_horario.h"
#include "ui_medico_horario.h"

medico_horario::medico_horario(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::medico_horario)
{
    ui->setupUi(this);
}

medico_horario::~medico_horario()
{
    delete ui;
}
