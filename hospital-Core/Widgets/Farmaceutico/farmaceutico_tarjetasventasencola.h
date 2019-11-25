#ifndef FARMACEUTICO_TARJETASVENTASENCOLA_H
#define FARMACEUTICO_TARJETASVENTASENCOLA_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>

class farmaceutico_realizarVentas;
namespace Ui {
class farmaceutico_tarjetasventasencola;
}

class farmaceutico_tarjetasventasencola : public QWidget
{
    Q_OBJECT

public:
    explicit farmaceutico_tarjetasventasencola(farmaceutico_realizarVentas *parent = nullptr);
    ~farmaceutico_tarjetasventasencola();
    void insertarDatos(QString, QString, QString);
    void setDatos();

private slots:

    void on_Cantidad_valueChanged(int arg1);


private:
    Ui::farmaceutico_tarjetasventasencola *ui;
    farmaceutico_realizarVentas *padre;
    int can;
    QString nombre;
    QString precio;
    float Total;
    QString id;
    QStringList ides;
};

#endif // FARMACEUTICO_TARJETASVENTASENCOLA_H
