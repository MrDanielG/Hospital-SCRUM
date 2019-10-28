#include "administrador_info_tip.h"
#include "ui_administrador_info_tip.h"

administrador_info_tip::administrador_info_tip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administrador_info_tip)
{
    ui->setupUi(this);
}

administrador_info_tip::~administrador_info_tip()
{
    delete ui;
}
