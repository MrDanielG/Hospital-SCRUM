#ifndef RECEPCIONISTA_CITAS_H
#define RECEPCIONISTA_CITAS_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include "Widgets/Recepcionista/recepcion_tarjeta_citas.h"

namespace Ui {
class recepcionista_citas;
}

class recepcionista_citas : public QWidget
{
    Q_OBJECT

public:
    explicit recepcionista_citas(QWidget *parent = nullptr);
    ~recepcionista_citas();
    void insertarDatos();
    void limpiarCatalogo();
    void mostrarCitas();
    void mostrarOperaciones();

private slots:


    void on_btnCitas_3_clicked();

    void on_btnCitas_4_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_btnCitas_clicked();

    void on_btnCitas_2_clicked();

    void on_btn_agendarCita_clicked();

    void on_operacion_btn_agendar_clicked();

private:
    Ui::recepcionista_citas *ui;
    QSqlDatabase mDatabase;
    int seccionactivada=1;
};

#endif // RECEPCIONISTA_CITAS_H
