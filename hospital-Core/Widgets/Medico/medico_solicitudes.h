#ifndef MEDICO_SOLICITUDES_H
#define MEDICO_SOLICITUDES_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class medico_solicitudes;
}

class medico_solicitudes : public QWidget
{
    Q_OBJECT

public:
    explicit medico_solicitudes(QWidget *parent = nullptr);
    ~medico_solicitudes();
    void setIdMedico(QString);
    void limpiarCatalogo();
    void inicializar();

private slots:
    void on_btn_solicitudesEspera_clicked();

    void on_btn_solicitudesRechazadas_clicked();

    void on_btn_solicitudesAprobadas_clicked();

private:
    Ui::medico_solicitudes *ui;
    QString idMedico;
    QSqlDatabase mDatabase;
};

#endif // MEDICO_SOLICITUDES_H
