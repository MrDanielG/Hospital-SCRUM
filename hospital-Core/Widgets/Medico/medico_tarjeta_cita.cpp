#include "medico_tarjeta_cita.h"
#include "ui_medico_tarjeta_cita.h"
#include <Widgets/Medico/medico_generar_receta.h>
medico_tarjeta_cita::medico_tarjeta_cita(QString _nombre, QString _motivo, QString _foto, QString _idCita, QString _fecha, medico_generar_receta *parent) :
    QWidget(parent),
    ui(new Ui::medico_tarjeta_cita)
{
    ui->setupUi(this);

    ui->nombre_paciente->setText(_nombre);
    ui->concepto->setText(_motivo);
    ui->fecha_cita->setText(_fecha);
    QPixmap foto(_foto);
    ui->foto->setPixmap(foto);
    this->padre = parent;
    this->descripcion = _motivo;
    this->idCita = _idCita;
}

medico_tarjeta_cita::~medico_tarjeta_cita()
{
    delete ui;
}

void medico_tarjeta_cita::on_btn_seleccionar_clicked()
{
    this->padre->setReceta(this->idCita);
}
