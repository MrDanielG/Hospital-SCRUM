#include "info_medico.h"
#include "ui_info_medico.h"

info_medico::info_medico(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::info_medico)
{
    ui->setupUi(this);
}

info_medico::~info_medico()
{
    delete ui;
}
