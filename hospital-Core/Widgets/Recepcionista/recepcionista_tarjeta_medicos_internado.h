#ifndef RECEPCIONISTA_TARJETA_MEDICOS_INTERNADO_H
#define RECEPCIONISTA_TARJETA_MEDICOS_INTERNADO_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class recepcionista_tarjeta_medicos_internado;
}

class recepcionista_tarjeta_medicos_internado : public QWidget
{
    Q_OBJECT

public:
    explicit recepcionista_tarjeta_medicos_internado(QString idpersona, QString idmedico, QString nombre, QString paterno, QString materno, QString calificacion, QString foto, QString especialidad, QWidget *parent = nullptr);
    ~recepcionista_tarjeta_medicos_internado();
    void insertarDatos();

private:
    Ui::recepcionista_tarjeta_medicos_internado *ui;
    QSqlDatabase mDatabase;
    QString nombre, especialidad, foto, idpersona, idmedico, paterno, materno, calificacion;
};

#endif // RECEPCIONISTA_TARJETA_MEDICOS_INTERNADO_H
