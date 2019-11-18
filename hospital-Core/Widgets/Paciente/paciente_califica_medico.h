#ifndef PACIENTE_CALIFICA_MEDICO_H
#define PACIENTE_CALIFICA_MEDICO_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class Paciente_Califica_Medico;
}

class Paciente_Califica_Medico : public QDialog
{
    Q_OBJECT

public:
    explicit Paciente_Califica_Medico(QString cita,QString med,QWidget *parent = nullptr);
    ~Paciente_Califica_Medico();

private slots:
    void on_btn1Estrella_clicked();
    void on_btn2Estrellas_clicked();
    void on_btn3Estrellas_clicked();
    void on_btn4Estrellas_clicked();
    void on_btn5Estrellas_clicked();
    void on_btn_enviarCalif_clicked();

private:
    Ui::Paciente_Califica_Medico *ui;
    QSqlDatabase mDatabase;
    QString idMed;
    QString id_cita;
    QString ruta,ruta1;
    QString NumEstrellas = "0";
};

#endif // PACIENTE_CALIFICA_MEDICO_H
