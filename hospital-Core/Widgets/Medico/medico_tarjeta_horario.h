#ifndef MEDICO_TARJETA_HORARIO_H
#define MEDICO_TARJETA_HORARIO_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class medico_tarjeta_horario;
}

class medico_tarjeta_horario : public QWidget
{
    Q_OBJECT

public:
    explicit medico_tarjeta_horario(QString nombre, QString paterno, QString materno, QString motivo, QString hInicio, QString hFin, QString foto,QString idCita, QWidget *parent = nullptr);
    ~medico_tarjeta_horario();
    void insertarDatos();

private slots:
    void on_btn_gestionar_medico_tarjeta_horario_clicked();

private:
    Ui::medico_tarjeta_horario *ui;
    QSqlDatabase mDatabase;
    QString nombre, paterno, materno, motivo, hInicio, hFin, foto,idCita;
};

#endif // MEDICO_TARJETA_HORARIO_H
