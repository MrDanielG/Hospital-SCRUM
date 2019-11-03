#ifndef MEDICO_RECHAZAR_CITA_MEDICA_H
#define MEDICO_RECHAZAR_CITA_MEDICA_H

#include <QDialog>

namespace Ui {
class medico_rechazar_cita_medica;
}

class medico_rechazar_cita_medica : public QDialog
{
    Q_OBJECT

public:
    explicit medico_rechazar_cita_medica(QWidget *parent = nullptr);
    ~medico_rechazar_cita_medica();

private:
    Ui::medico_rechazar_cita_medica *ui;
};

#endif // MEDICO_RECHAZAR_CITA_MEDICA_H
