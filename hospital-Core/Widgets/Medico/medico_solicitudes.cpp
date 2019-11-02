#include "medico_solicitudes.h"
#include "ui_medico_solicitudes.h"

medico_solicitudes::medico_solicitudes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::medico_solicitudes)
{
    ui->setupUi(this);
}

medico_solicitudes::~medico_solicitudes()
{
    delete ui;
}
