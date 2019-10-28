#include "administrador_landpage.h"
#include "ui_administrador_landpage.h"

administrador_landpage::administrador_landpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::administrador_landpage)
{
    ui->setupUi(this);
}

administrador_landpage::~administrador_landpage()
{
    delete ui;
}
