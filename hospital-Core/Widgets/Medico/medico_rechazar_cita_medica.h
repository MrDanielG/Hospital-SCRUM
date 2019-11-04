#ifndef MEDICO_RECHAZAR_CITA_MEDICA_H
#define MEDICO_RECHAZAR_CITA_MEDICA_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class medico_rechazar_cita_medica;
}

class medico_rechazar_cita_medica : public QDialog
{
    Q_OBJECT

public:
    explicit medico_rechazar_cita_medica(QString idCita, QWidget *parent = nullptr);
    ~medico_rechazar_cita_medica();

private slots:
    void on_btn_cancelar_rechazo_cita_clicked();

private:
    Ui::medico_rechazar_cita_medica *ui;
    QSqlDatabase mDatabase;
    QString idCita;
};

#endif // MEDICO_RECHAZAR_CITA_MEDICA_H
