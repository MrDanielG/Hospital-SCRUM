#ifndef PACIENTE_CREAR_CITA_H
#define PACIENTE_CREAR_CITA_H

#include <QDialog>
#include <QSqlDatabase>
namespace Ui {
class paciente_crear_cita;
}

class paciente_crear_cita : public QDialog
{
    Q_OBJECT

public:
    explicit paciente_crear_cita(QString, QWidget *parent = nullptr);
    ~paciente_crear_cita();

private slots:
    void on_btn_agendarCita_clicked();

private:
    Ui::paciente_crear_cita *ui;
    QSqlDatabase mDatabase;
    QString idUsuarioPaciente;
};

#endif // PACIENTE_CREAR_CITA_H