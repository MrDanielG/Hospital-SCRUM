#ifndef TARJETA_SERVICIOS_H
#define TARJETA_SERVICIOS_H

#include <QWidget>
#include <QSqlDatabase>


namespace Ui {
class Tarjeta_Servicios;
}

class Tarjeta_Servicios : public QWidget
{
    Q_OBJECT

public:
    explicit Tarjeta_Servicios(QString foto, QString nombre, QWidget *parent = nullptr);
    ~Tarjeta_Servicios();
    void insertarDatos();

private:
    Ui::Tarjeta_Servicios *ui;
    QSqlDatabase mDatabase;
    QString foto, nombre;
};

#endif // TARJETA_SERVICIOS_H
