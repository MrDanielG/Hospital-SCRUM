#include "medico_modificar.h"
#include "ui_medico_modificar.h"

medico_modificar::medico_modificar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::medico_modificar)
{
    ui->setupUi(this);
}

medico_modificar::~medico_modificar()
{
    delete ui;
}

void medico_modificar::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
