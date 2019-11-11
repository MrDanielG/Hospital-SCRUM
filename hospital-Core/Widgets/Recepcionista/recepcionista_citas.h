#ifndef RECEPCIONISTA_CITAS_H
#define RECEPCIONISTA_CITAS_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include "Widgets/Recepcionista/recepcion_tarjeta_citas.h"

namespace Ui {
class recepcionista_citas;
}

class recepcionista_citas : public QWidget
{
    Q_OBJECT

public:
    explicit recepcionista_citas(QWidget *parent = nullptr);
    ~recepcionista_citas();
    void insertarDatos();

private slots:


private:
    Ui::recepcionista_citas *ui;
    QSqlDatabase mDatabase;
};

#endif // RECEPCIONISTA_CITAS_H
