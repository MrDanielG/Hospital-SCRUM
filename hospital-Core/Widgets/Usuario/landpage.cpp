#include "landpage.h"
#include "ui_landpage.h"
#include "Widgets/Usuario/usuario_tip.h"

landpage::landpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::landpage)
{
    ui->setupUi(this);

    usuario_tip tip_dia;
    tip_dia.exec();
}

landpage::~landpage()
{
    delete ui;
}

void landpage::on_btn_registrarse_clicked()
{
    registrar dialogo_registro;
    dialogo_registro.exec();
}
