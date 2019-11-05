#include "administrador_catalogo_cancelacion_cita.h"
#include "ui_administrador_catalogo_cancelacion_cita.h"

administrador_catalogo_cancelacion_cita::administrador_catalogo_cancelacion_cita(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::administrador_catalogo_cancelacion_cita)
{
    ui->setupUi(this);
}

administrador_catalogo_cancelacion_cita::~administrador_catalogo_cancelacion_cita()
{
    delete ui;
}
