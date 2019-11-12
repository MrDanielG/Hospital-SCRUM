#include "medico_generar_receta.h"
#include "ui_medico_generar_receta.h"

medico_generar_receta::medico_generar_receta(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::medico_generar_receta)
{
    ui->setupUi(this);
}

medico_generar_receta::~medico_generar_receta()
{
    delete ui;
}
