#include "tarjeta_remedios.h"
#include "ui_tarjeta_remedios.h"

tarjeta_remedios::tarjeta_remedios(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tarjeta_remedios)
{
    ui->setupUi(this);
}

tarjeta_remedios::~tarjeta_remedios()
{
    delete ui;
}

void tarjeta_remedios::insertarDatos(QString id, QString nombre, QString descripcion, QString imagen){
    QPixmap imag(imagen);
    ui->imagen->setPixmap(imag);
    ui->descripcion->setPlainText(descripcion);
    ui->nombre->setText(nombre);
    this->id = id;

}
