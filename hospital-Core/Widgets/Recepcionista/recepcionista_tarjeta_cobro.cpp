#include "recepcionista_tarjeta_cobro.h"
#include "ui_recepcionista_tarjeta_cobro.h"
#include "Widgets/Recepcionista/recepcionista_cobrar_estancia.h"
recepcionista_tarjeta_cobro::recepcionista_tarjeta_cobro(QString _idInternado, QString _nombre, QString _habitacion, QString _foto, QString _fecha, recepcionista_cobrar_estancia *parent) :
    QWidget(parent),
    ui(new Ui::recepcionista_tarjeta_cobro)
{
    ui->setupUi(this);

    this->idInterno = _idInternado;
    ui->nombre_paciente->setText(_nombre);
    ui->fecha_inicio->setText(_fecha);
    ui->habitacion->setText("Habitación: " + _habitacion);
    QPixmap img(_foto);
    ui->foto->setPixmap(img);
    this->padre = parent;
}

recepcionista_tarjeta_cobro::~recepcionista_tarjeta_cobro()
{
    delete ui;
}

void recepcionista_tarjeta_cobro::on_btn_seleccionar_clicked()
{
    this->padre->inicializarRececta(this->idInterno);
}
