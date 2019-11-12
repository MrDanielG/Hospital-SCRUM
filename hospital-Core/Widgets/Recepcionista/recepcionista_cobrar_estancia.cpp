#include "recepcionista_cobrar_estancia.h"
#include "ui_recepcionista_cobrar_estancia.h"

recepcionista_cobrar_estancia::recepcionista_cobrar_estancia(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::recepcionista_cobrar_estancia)
{
    ui->setupUi(this);
}

recepcionista_cobrar_estancia::~recepcionista_cobrar_estancia()
{
    delete ui;
}
