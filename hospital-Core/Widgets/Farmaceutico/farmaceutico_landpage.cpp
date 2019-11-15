#include "farmaceutico_landpage.h"
#include "ui_farmaceutico_landpage.h"

farmaceutico_landpage::farmaceutico_landpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::farmaceutico_landpage)
{
    ui->setupUi(this);
}

farmaceutico_landpage::~farmaceutico_landpage()
{
    delete ui;
}
