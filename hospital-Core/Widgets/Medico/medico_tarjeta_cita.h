#ifndef MEDICO_TARJETA_CITA_H
#define MEDICO_TARJETA_CITA_H

#include <QWidget>
class medico_generar_receta;
namespace Ui {
class medico_tarjeta_cita;
}

class medico_tarjeta_cita : public QWidget
{
    Q_OBJECT

public:
    explicit medico_tarjeta_cita(QString, QString, QString, QString, QString, medico_generar_receta *parent = nullptr);
    ~medico_tarjeta_cita();

private slots:
    void on_btn_seleccionar_clicked();

private:
    Ui::medico_tarjeta_cita *ui;
    medico_generar_receta *padre;
    QString descripcion;
    QString idCita;
};

#endif // MEDICO_TARJETA_CITA_H
