#ifndef ADMINISTRADOR_INFO_SERVICIOS_H
#define ADMINISTRADOR_INFO_SERVICIOS_H

#include <QDialog>

namespace Ui {
class administrador_info_servicios;
}

class administrador_info_servicios : public QDialog
{
    Q_OBJECT

public:
    explicit administrador_info_servicios(QWidget *parent = nullptr);
    ~administrador_info_servicios();

private:
    Ui::administrador_info_servicios *ui;
};

#endif // ADMINISTRADOR_INFO_SERVICIOS_H
