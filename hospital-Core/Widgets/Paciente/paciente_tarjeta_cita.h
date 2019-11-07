#ifndef PACIENTE_TARJETA_CITA_H
#define PACIENTE_TARJETA_CITA_H

#include <QWidget>

namespace Ui {
class paciente_tarjeta_cita;
}

class paciente_tarjeta_cita : public QWidget
{
    Q_OBJECT

public:
    explicit paciente_tarjeta_cita(QWidget *parent = nullptr);
    ~paciente_tarjeta_cita();

private:
    Ui::paciente_tarjeta_cita *ui;
};

#endif // PACIENTE_TARJETA_CITA_H
