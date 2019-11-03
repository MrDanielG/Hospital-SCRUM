#ifndef MEDICO_INFO_CITA_MEDICA_H
#define MEDICO_INFO_CITA_MEDICA_H

#include <QWidget>

namespace Ui {
class medico_info_cita_medica;
}

class medico_info_cita_medica : public QWidget
{
    Q_OBJECT

public:
    explicit medico_info_cita_medica(QWidget *parent = nullptr);
    ~medico_info_cita_medica();

private:
    Ui::medico_info_cita_medica *ui;
};

#endif // MEDICO_INFO_CITA_MEDICA_H
