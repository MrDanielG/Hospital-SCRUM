#include "recepcionista_tarjeta_cobro.h"
#include "ui_recepcionista_tarjeta_cobro.h"

recepcionista_tarjeta_cobro::recepcionista_tarjeta_cobro(QString _idInternado, QString _nombre, QString _habitacion, QString _foto, QString _fecha, QWidget *parent) :
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
}

recepcionista_tarjeta_cobro::~recepcionista_tarjeta_cobro()
{
    delete ui;
}
