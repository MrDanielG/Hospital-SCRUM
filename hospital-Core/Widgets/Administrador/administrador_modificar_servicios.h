#ifndef ADMINISTRADOR_MODIFICAR_SERVICIOS_H
#define ADMINISTRADOR_MODIFICAR_SERVICIOS_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
namespace Ui {
class administrador_modificar_servicios;
}

class administrador_modificar_servicios : public QDialog
{
    Q_OBJECT

public:
    explicit administrador_modificar_servicios(QString, QString, QString, QString, QWidget *parent = nullptr);
    ~administrador_modificar_servicios();

private:
    Ui::administrador_modificar_servicios *ui;
    QSqlDatabase mDatabase;
    QString id_servicio, nombre, info, foto;
};

#endif // ADMINISTRADOR_MODIFICAR_SERVICIOS_H
