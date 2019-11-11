#ifndef RECEPCIONISTA_TARJETA_OPERACIONES_H
#define RECEPCIONISTA_TARJETA_OPERACIONES_H

#include <QWidget>

namespace Ui {
class recepcionista_tarjeta_operaciones;
}

class recepcionista_tarjeta_operaciones : public QWidget
{
    Q_OBJECT

public:
    explicit recepcionista_tarjeta_operaciones(QWidget *parent = nullptr);
    ~recepcionista_tarjeta_operaciones();

private:
    Ui::recepcionista_tarjeta_operaciones *ui;
};

#endif // RECEPCIONISTA_TARJETA_OPERACIONES_H
