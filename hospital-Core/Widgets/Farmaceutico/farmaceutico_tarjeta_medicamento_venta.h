#ifndef FARMACEUTICO_TARJETA_MEDICAMENTO_VENTA_H
#define FARMACEUTICO_TARJETA_MEDICAMENTO_VENTA_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>

class farmaceutico_realizarVentas;

namespace Ui {
class farmaceutico_tarjeta_medicamento_venta;
}

class farmaceutico_tarjeta_medicamento_venta : public QWidget
{
    Q_OBJECT

public:
    explicit farmaceutico_tarjeta_medicamento_venta(farmaceutico_realizarVentas *parent = nullptr);
    ~farmaceutico_tarjeta_medicamento_venta();
    void insertarDatos(QString nombre, QString precio, QString cantidad, QString premedicado, QString id);
    QString getID();

private slots:
    void on_btn_agregaracola_clicked();

private:
    Ui::farmaceutico_tarjeta_medicamento_venta *ui;
    QSqlDatabase mDatabase;
    QString id;
    farmaceutico_realizarVentas *padre;
};

#endif // FARMACEUTICO_TARJETA_MEDICAMENTO_VENTA_H
