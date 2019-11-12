#ifndef MEDICO_TARJETA_CITA_H
#define MEDICO_TARJETA_CITA_H

#include <QWidget>

namespace Ui {
class medico_tarjeta_cita;
}

class medico_tarjeta_cita : public QWidget
{
    Q_OBJECT

public:
    explicit medico_tarjeta_cita(QWidget *parent = nullptr);
    ~medico_tarjeta_cita();

private:
    Ui::medico_tarjeta_cita *ui;
};

#endif // MEDICO_TARJETA_CITA_H
