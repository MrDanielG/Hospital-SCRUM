#include "recepcionistalandpage.h"
#include "ui_recepcionistalandpage.h"

recepcionistaLandpage::recepcionistaLandpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::recepcionistaLandpage)
{
    ui->setupUi(this);
}

recepcionistaLandpage::~recepcionistaLandpage()
{
    delete ui;
}
