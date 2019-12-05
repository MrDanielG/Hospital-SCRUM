#ifndef FARMACEUTICO_TARJETA_MEDICAMENTO_H
#define FARMACEUTICO_TARJETA_MEDICAMENTO_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

class farmaceutico_medicamentos; //Agregamos el padre

namespace Ui {
class farmaceutico_tarjeta_medicamento;
}

class farmaceutico_tarjeta_medicamento : public QWidget
{
    Q_OBJECT

public:
    explicit farmaceutico_tarjeta_medicamento(QString id, QString nombre, QString tipo, QString descripcion, QString costo, QString cantidad, QString premedicado, farmaceutico_medicamentos *parent = nullptr); //drfinimos al padre
    ~farmaceutico_tarjeta_medicamento();
    void insertarDatos();

private slots:
    void on_btn_agregar_medicamento_clicked();

private:
    Ui::farmaceutico_tarjeta_medicamento *ui;
    QSqlDatabase mDatabase;
    farmaceutico_medicamentos *padre;
    QString id, nombre, tipo, descripcion, costo, cantidad, premedicado;
};

#endif // FARMACEUTICO_TARJETA_MEDICAMENTO_H
