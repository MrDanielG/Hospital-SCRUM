#ifndef FARMACEUTICO_MODIFICAR_MEDICAMENTOS_H
#define FARMACEUTICO_MODIFICAR_MEDICAMENTOS_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class farmaceutico_modificar_medicamentos;
}

class farmaceutico_modificar_medicamentos : public QDialog
{
    Q_OBJECT

public:
    explicit farmaceutico_modificar_medicamentos(QString id, QString nombre, QString tipo, QString descripcion, QString costo, QString cantidad, QString premedicado, QWidget *parent = nullptr);
    ~farmaceutico_modificar_medicamentos();
    void insertarDatos();

private slots:
    void on_btn_modificar_medicamento_clicked();

    void on_btn_cancelar_modificacion_clicked();

private:
    Ui::farmaceutico_modificar_medicamentos *ui;
    QSqlDatabase mDatabase;
    QString id, nombre, tipo, descripcion, costo, cantidad, premedicado;
};

#endif // FARMACEUTICO_MODIFICAR_MEDICAMENTOS_H
