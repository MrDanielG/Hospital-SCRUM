#ifndef FARMACEUTICO_GESTIONAR_MEDICAMENTO_H
#define FARMACEUTICO_GESTIONAR_MEDICAMENTO_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class farmaceutico_gestionar_medicamento;
}

class farmaceutico_gestionar_medicamento : public QDialog
{
    Q_OBJECT

public:
    explicit farmaceutico_gestionar_medicamento(QString id, QString nombre, QString tipo, QString descripcion, QString costo, QString cantidad, QString premedicado, QWidget *parent = nullptr);
    ~farmaceutico_gestionar_medicamento();
    void insertarDatos();

private slots:
    void on_btn_modificar_medicamento_clicked();

    void on_btn_eliminar_medicamento_clicked();

private:
    Ui::farmaceutico_gestionar_medicamento *ui;
    QSqlDatabase mDatabase;
    QString id, nombre, tipo, descripcion, costo, cantidad, premedicado;
};

#endif // FARMACEUTICO_GESTIONAR_MEDICAMENTO_H
