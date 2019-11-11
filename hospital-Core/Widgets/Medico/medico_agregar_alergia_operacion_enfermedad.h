#ifndef MEDICO_AGREGAR_ALERGIA_OPERACION_ENFERMEDAD_H
#define MEDICO_AGREGAR_ALERGIA_OPERACION_ENFERMEDAD_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class medico_agregar_alergia_operacion_enfermedad;
}

class medico_agregar_alergia_operacion_enfermedad : public QDialog
{
    Q_OBJECT

public:
    explicit medico_agregar_alergia_operacion_enfermedad(QString idExpediente,QString tipoInsercion, QWidget *parent = nullptr);
    ~medico_agregar_alergia_operacion_enfermedad();

private slots:
    void on_btn_cancelar_alergia_clicked();

    void on_btn_cancelar_enfermedad_clicked();

    void on_btn_cancelar_operacion_clicked();

    void on_btn_agregar_alergia_clicked();

    void on_btn_agregar_enfermedad_clicked();

    void on_btn_agregar_operacion_clicked();

private:
    Ui::medico_agregar_alergia_operacion_enfermedad *ui;
    QString idExpediente;
    QSqlDatabase mDatabase;
};

#endif // MEDICO_AGREGAR_ALERGIA_OPERACION_ENFERMEDAD_H
