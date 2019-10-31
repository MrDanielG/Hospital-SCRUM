#ifndef ADMINISTRADOR_MODIFICAR_SERVICIOS_H
#define ADMINISTRADOR_MODIFICAR_SERVICIOS_H

#include <QDialog>

namespace Ui {
class administrador_modificar_servicios;
}

class administrador_modificar_servicios : public QDialog
{
    Q_OBJECT

public:
    explicit administrador_modificar_servicios(QWidget *parent = nullptr);
    ~administrador_modificar_servicios();

private:
    Ui::administrador_modificar_servicios *ui;
};

#endif // ADMINISTRADOR_MODIFICAR_SERVICIOS_H
