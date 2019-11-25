#ifndef EMPLEADO_TARJETA_PERMISO_H
#define EMPLEADO_TARJETA_PERMISO_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class empleado_tarjeta_permiso;
}

class empleado_tarjeta_permiso : public QDialog
{
    Q_OBJECT

public:
    explicit empleado_tarjeta_permiso(QString idPermiso,QString foto,QString f_inicio,QString f_fin, QWidget *parent = nullptr);
    ~empleado_tarjeta_permiso();

private:
    Ui::empleado_tarjeta_permiso *ui;
    QString foto,f_inicio,f_fin,idPermiso;
};

#endif // EMPLEADO_TARJETA_PERMISO_H
