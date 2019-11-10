#ifndef RECEPCIONISTA_TARJETA_PACIENTES_INTERNADOS_H
#define RECEPCIONISTA_TARJETA_PACIENTES_INTERNADOS_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class recepcionista_tarjeta_pacientes_internados;
}

class recepcionista_tarjeta_pacientes_internados : public QWidget
{
    Q_OBJECT

public:
    explicit recepcionista_tarjeta_pacientes_internados(QString id, QString nombre, QString paterno, QString materno, QString foto, QString curp, QWidget *parent = nullptr);
    ~recepcionista_tarjeta_pacientes_internados();
    void insertarDatos();

private slots:
    void on_btn_visualizar_clicked();

private:
    Ui::recepcionista_tarjeta_pacientes_internados *ui;
    QSqlDatabase mDatabase;
    QString id, nombre, paterno, materno, foto, curp;
};

#endif // RECEPCIONISTA_TARJETA_PACIENTES_INTERNADOS_H
