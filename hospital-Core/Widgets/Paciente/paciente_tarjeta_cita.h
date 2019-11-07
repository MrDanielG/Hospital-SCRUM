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
    explicit paciente_tarjeta_cita(QString, QString, QString, QString, QString, QString, QString, QWidget *parent = nullptr);
    ~paciente_tarjeta_cita();
    void inicializarTarjeta();
private:
    Ui::paciente_tarjeta_cita *ui;
    QSqlDatabase mDatabase;
    QString id_cita;
    QString descripcion;
    QString fecha;
    QString horaInicioFin;
    QString estadoCita;
    QString nombreMedico;
    QString nombreUsuario;
};

#endif // PACIENTE_TARJETA_CITA_H
