#ifndef ADMINISTRADOR_TARJETA_SERVICIOS_H
#define ADMINISTRADOR_TARJETA_SERVICIOS_H

#include <QWidget>

namespace Ui {
class administrador_tarjeta_servicios;
}

class administrador_tarjeta_servicios : public QWidget
{
    Q_OBJECT

public:
    explicit administrador_tarjeta_servicios(QWidget *parent = nullptr);
    ~administrador_tarjeta_servicios();

private:
    Ui::administrador_tarjeta_servicios *ui;
};

#endif // ADMINISTRADOR_TARJETA_SERVICIOS_H
