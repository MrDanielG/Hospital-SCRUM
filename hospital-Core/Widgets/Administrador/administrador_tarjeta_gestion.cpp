#include "administrador_tarjeta_gestion.h"
#include "ui_administrador_tarjeta_gestion.h"
#include "Widgets/Administrador/administrador_info_gestion.h"
administrador_tarjeta_gestion::administrador_tarjeta_gestion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::administrador_tarjeta_gestion)
{
    ui->setupUi(this);

    this->id = id;
    this->nombre = nombre;
    this->img = img;

    QPixmap imagen(img);
    ui->img_persona->setPixmap(imagen);
    ui->lbl_nombre->setText(this->nombre);
}

administrador_tarjeta_gestion::~administrador_tarjeta_gestion()
{
    delete ui;
}

//void administrador_tarjeta_gestion::on_btn_gestionar_clicked()
//{
//    administrador_info_gestion infoGestion;
//    infoGestion.exec();
//}
