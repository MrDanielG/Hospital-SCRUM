#ifndef PACIENTE_REAGENDAR_CITA_H
#define PACIENTE_REAGENDAR_CITA_H

#include <QDialog>

namespace Ui {
class paciente_Reagendar_cita;
}

class paciente_Reagendar_cita : public QDialog
{
    Q_OBJECT

public:
    explicit paciente_Reagendar_cita(QWidget *parent = nullptr);
    ~paciente_Reagendar_cita();
    bool getBand();

private slots:
    void on_btn_reagendar_SI_clicked();

    void on_btn_reagendar_NO_clicked();

private:
    Ui::paciente_Reagendar_cita *ui;
    bool bandera;
};

#endif // PACIENTE_REAGENDAR_CITA_H
