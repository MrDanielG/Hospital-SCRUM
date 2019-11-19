#ifndef FARMACEUTICO_REALIZARVENTAS_H
#define FARMACEUTICO_REALIZARVENTAS_H


#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include "Widgets/Farmaceutico/farmaceutico_tarjeta_medicamento_venta.h"
#include "Widgets/Farmaceutico/farmaceutico_tarjetasventasencola.h"

namespace Ui {
class farmaceutico_realizarVentas;
}

class farmaceutico_realizarVentas : public QWidget
{
    Q_OBJECT

public:
    explicit farmaceutico_realizarVentas(QWidget *parent = nullptr);
    ~farmaceutico_realizarVentas();
    void limpiarCatalogo();
    void insertarVentas(QString);

private slots:
    void on_BuscarMedicamento_textChanged(const QString &arg1);

private:
    Ui::farmaceutico_realizarVentas *ui;
    QSqlDatabase mDatabase;
};

#endif // FARMACEUTICO_REALIZARVENTAS_H
