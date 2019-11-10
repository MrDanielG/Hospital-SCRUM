#ifndef RECEPCIONISTA_DIALOGO_GESTIONAR_INTERNADO_H
#define RECEPCIONISTA_DIALOGO_GESTIONAR_INTERNADO_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QDate>

namespace Ui {
class recepcionista_dialogo_gestionar_internado;
}

class recepcionista_dialogo_gestionar_internado : public QDialog
{
    Q_OBJECT

public:
    explicit recepcionista_dialogo_gestionar_internado(QString idPaciente, QString paciente, QString medico, QString habitacion, QDate fecha_fin, QString foto, QWidget *parent = nullptr);
    ~recepcionista_dialogo_gestionar_internado();
    void insertarDatos();

private slots:
    void on_btn_cancelar_internado_clicked();

    void on_btn_agregar_internado_2_clicked();

private:
    Ui::recepcionista_dialogo_gestionar_internado *ui;
    QSqlDatabase mDatabase;
    QString idPaciente, paciente, medico, habitacion, foto;
    QDate fecha_fin;
};

#endif // RECEPCIONISTA_DIALOGO_GESTIONAR_INTERNADO_H
