#include "catalogo_doctores.h"
#include "ui_catalogo_doctores.h"

catalogo_doctores::catalogo_doctores(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::catalogo_doctores)
{
    ui->setupUi(this);
}

catalogo_doctores::~catalogo_doctores()
{
    delete ui;
}
