#ifndef FARMACEUTICO_REALIZARVENTAS_H
#define FARMACEUTICO_REALIZARVENTAS_H

#include <QWidget>

namespace Ui {
class farmaceutico_realizarVentas;
}

class farmaceutico_realizarVentas : public QWidget
{
    Q_OBJECT

public:
    explicit farmaceutico_realizarVentas(QWidget *parent = nullptr);
    ~farmaceutico_realizarVentas();

private:
    Ui::farmaceutico_realizarVentas *ui;
};

#endif // FARMACEUTICO_REALIZARVENTAS_H
