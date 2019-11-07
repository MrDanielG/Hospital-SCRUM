#ifndef MEDICO_TARJETA_CITARECHAZADA_H
#define MEDICO_TARJETA_CITARECHAZADA_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class medico_tarjeta_CitaRechazada;
}

class medico_tarjeta_CitaRechazada : public QWidget
{
    Q_OBJECT

public:
    explicit medico_tarjeta_CitaRechazada(QString nombre, QString paterno, QString materno, QString motivo, QString hInicio, QString hFin, QString foto,QWidget *parent = nullptr);
    ~medico_tarjeta_CitaRechazada();
    void insertarDatos();

private:
    Ui::medico_tarjeta_CitaRechazada *ui;
    QSqlDatabase mDatabase;
    QString nombre, paterno, materno, motivo, hInicio, hFin, foto;
};

#endif // MEDICO_TARJETA_CITARECHAZADA_H
