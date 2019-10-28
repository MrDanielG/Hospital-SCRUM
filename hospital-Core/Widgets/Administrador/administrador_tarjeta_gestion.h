#ifndef ADMINISTRADOR_TARJETA_GESTION_H
#define ADMINISTRADOR_TARJETA_GESTION_H

#include <QWidget>

namespace Ui {
class administrador_tarjeta_gestion;
}

class administrador_tarjeta_gestion : public QWidget
{
    Q_OBJECT

public:
    explicit administrador_tarjeta_gestion(QWidget *parent = nullptr);
    ~administrador_tarjeta_gestion();

private:
    Ui::administrador_tarjeta_gestion *ui;
};

#endif // ADMINISTRADOR_TARJETA_GESTION_H
