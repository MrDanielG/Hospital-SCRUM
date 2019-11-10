#ifndef RECEPCIONISTA_TARJETA_INTERNADOS_H
#define RECEPCIONISTA_TARJETA_INTERNADOS_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class recepcionista_tarjeta_internados;
}

class recepcionista_tarjeta_internados : public QWidget
{
    Q_OBJECT

public:
    explicit recepcionista_tarjeta_internados(QString paciente, QString medico, QString habitacion, QString fecha_fin, QString foto, QWidget *parent = nullptr);
    ~recepcionista_tarjeta_internados();
    void insertarDatos();

private:
    Ui::recepcionista_tarjeta_internados *ui;
    QSqlDatabase mDatabase;
    QString paciente, medico, habitacion, fecha_fin, foto;
};

#endif // RECEPCIONISTA_TARJETA_INTERNADOS_H
