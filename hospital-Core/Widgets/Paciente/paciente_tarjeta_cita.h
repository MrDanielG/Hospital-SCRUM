#ifndef PACIENTE_TARJETA_CITA_H
#define PACIENTE_TARJETA_CITA_H

#include <QWidget>
#include <QSqlDatabase>
namespace Ui {
class paciente_tarjeta_cita;
}

class paciente_tarjeta_cita : public QWidget
{
    Q_OBJECT

public:
    explicit paciente_tarjeta_cita(QString, QString, QString, QString, QString, QString, QString, QString, QString, QWidget *parent = nullptr);
    ~paciente_tarjeta_cita();
    void inicializarTarjeta();
private slots:
    void on_btn_gestionar_clicked();

    void on_btn_calificar_clicked();

private:
    Ui::paciente_tarjeta_cita *ui;
    QSqlDatabase mDatabase;
    QString id_cita;
    QString motivo;
    QString descripcion;
    QString fecha;
    QString horaInicioFin;
    QString idMed;
    QString idPac;
    QString idPagos;
    QString estadoCita;
};

#endif // PACIENTE_TARJETA_CITA_H
