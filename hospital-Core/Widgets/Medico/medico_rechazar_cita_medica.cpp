#include "medico_rechazar_cita_medica.h"
#include "ui_medico_rechazar_cita_medica.h"

medico_rechazar_cita_medica::medico_rechazar_cita_medica(QString idCita, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::medico_rechazar_cita_medica)
{
    ui->setupUi(this);
    setWindowTitle("Rechazo de cita");
    this->idCita=idCita;
}

medico_rechazar_cita_medica::~medico_rechazar_cita_medica()
{
    delete ui;
}

void medico_rechazar_cita_medica::on_btn_cancelar_rechazo_cita_clicked()
{
    this->close();
}
