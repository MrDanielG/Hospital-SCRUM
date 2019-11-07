#ifndef PACIENTE_CREAR_CITA_H
#define PACIENTE_CREAR_CITA_H

#include <QDialog>

namespace Ui {
class paciente_crear_cita;
}

class paciente_crear_cita : public QDialog
{
    Q_OBJECT

public:
    explicit paciente_crear_cita(QWidget *parent = nullptr);
    ~paciente_crear_cita();

private:
    Ui::paciente_crear_cita *ui;
};

#endif // PACIENTE_CREAR_CITA_H
