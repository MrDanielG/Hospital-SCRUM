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
    explicit Tarjeta_Servicios(QString id, QString foto, QString nombre, QWidget *parent = nullptr);
    ~Tarjeta_Servicios();
    void insertarDatos();

private slots:
    void on_btn_visualizar_servicio_clicked();

private:
    Ui::Tarjeta_Servicios *ui;
    QSqlDatabase mDatabase;
    QString foto, nombre, id;
};

#endif // TARJETA_SERVICIOS_H
