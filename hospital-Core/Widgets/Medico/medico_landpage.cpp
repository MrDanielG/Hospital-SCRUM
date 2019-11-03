#include "medico_landpage.h"
#include "ui_medico_landpage.h"

medico_landPage::medico_landPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::medico_landPage)
{
    ui->setupUi(this);
}

medico_landPage::~medico_landPage()
{
    delete ui;
}
