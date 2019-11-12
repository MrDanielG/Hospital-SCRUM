#ifndef MEDICO_TARJETA_CITA_H
#define MEDICO_TARJETA_CITA_H

#include <QWidget>
#include <Widgets/Medico/medico_generar_receta.h>
namespace Ui {
class medico_tarjeta_cita;
}

class medico_tarjeta_cita : public QWidget
{
    Q_OBJECT

public:
    explicit medico_tarjeta_cita(QString, QString, QString, QString, QString, medico_generar_receta *parent = nullptr);
    ~medico_tarjeta_cita();

private:
    Ui::medico_tarjeta_cita *ui;
};

#endif // MEDICO_TARJETA_CITA_H
