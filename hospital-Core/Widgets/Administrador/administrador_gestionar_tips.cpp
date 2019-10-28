#include "administrador_gestionar_tips.h"
#include "ui_administrador_gestionar_tips.h"

administrador_gestionar_tips::administrador_gestionar_tips(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::administrador_gestionar_tips)
{
    ui->setupUi(this);
}

administrador_gestionar_tips::~administrador_gestionar_tips()
{
    delete ui;
}
