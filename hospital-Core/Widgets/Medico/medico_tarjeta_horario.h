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
    explicit medico_tarjeta_horario(QString nombre, QString paterno, QString materno, QString motivo, QString hInicio, QString hFin, QString foto, QWidget *parent = nullptr);
    ~medico_tarjeta_horario();
    void insertarDatos();

private:
    Ui::medico_tarjeta_horario *ui;
    QSqlDatabase mDatabase;
    QString nombre, paterno, materno, motivo, hInicio, hFin, foto;
};

#endif // MEDICO_TARJETA_HORARIO_H
