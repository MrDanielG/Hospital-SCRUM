#ifndef TARJETA_PERMISO_H
#define TARJETA_PERMISO_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class tarjeta_permiso;
}

class tarjeta_permiso : public QWidget
{
    Q_OBJECT

public:
    explicit tarjeta_permiso(QString idPermiso,QString foto,QString f_inicio,QString f_fin,QWidget *parent = nullptr);
    ~tarjeta_permiso();

private:
    Ui::tarjeta_permiso *ui;
    QString foto,f_inicio,f_fin,idPermiso;
};

#endif // TARJETA_PERMISO_H
