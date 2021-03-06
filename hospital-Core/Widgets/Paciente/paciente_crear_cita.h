#ifndef PACIENTE_CREAR_CITA_H
#define PACIENTE_CREAR_CITA_H

#include <QDialog>
#include <QSqlDatabase>
namespace Ui {
class paciente_crear_cita;
}

class QStringListModel;

class paciente_crear_cita : public QDialog
{
    Q_OBJECT

public:
    explicit paciente_crear_cita(QString, QString, QWidget *parent = nullptr);
    ~paciente_crear_cita();

private slots:
    void on_btn_agendarCita_clicked();
    void on_ButtonBuscaHorario_clicked();

    void on_btn_reagendar_cita_clicked();

private:
    Ui::paciente_crear_cita *ui;
    QSqlDatabase mDatabase;
    QString idUsuarioPaciente;
    QString idMedico;
    QString idCita;
};

#endif // PACIENTE_CREAR_CITA_H
