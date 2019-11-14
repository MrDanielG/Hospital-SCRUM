#ifndef FARMACEUTICO_TARJETA_MEDICAMENTO_VENTA_H
#define FARMACEUTICO_TARJETA_MEDICAMENTO_VENTA_H

#include <QWidget>

namespace Ui {
class farmaceutico_tarjeta_medicamento_venta;
}

class farmaceutico_tarjeta_medicamento_venta : public QWidget
{
    Q_OBJECT

public:
    explicit farmaceutico_tarjeta_medicamento_venta(QWidget *parent = nullptr);
    ~farmaceutico_tarjeta_medicamento_venta();

private:
    Ui::farmaceutico_tarjeta_medicamento_venta *ui;
};

#endif // FARMACEUTICO_TARJETA_MEDICAMENTO_VENTA_H
