#ifndef MEDICO_EXPEDIENTE_CLINICO_H
#define MEDICO_EXPEDIENTE_CLINICO_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <qsqlquerymodel.h>

namespace Ui {
class medico_expediente_clinico;
}

class medico_expediente_clinico : public QWidget
{
    Q_OBJECT

public:
    explicit medico_expediente_clinico(QString nombre, QString paterno, QString materno,QString foto,QString idCita, QWidget *parent = nullptr);
    ~medico_expediente_clinico();
    void cargarTablaAlergias();
    void cargarTablaOperaciones();
    void cargarTablaEnfermedades();

private slots:
    void on_btn_informacion_clicked();

    void on_btn_alergias_clicked();

    void on_btn_enfermedad_clicked();

    void on_btn_operacion_clicked();

    void on_btn_modificarDatos_clicked();

    void on_btn_GenerarExpediente_clicked();

    void on_table_alergias_clicked(const QModelIndex &index);

    void on_table_enfermedades_clicked(const QModelIndex &index);

    void on_table_operaciones_clicked(const QModelIndex &index);

    void on_btn_guardarCambios_clicked();

    void on_btn_eliminar_alergia_clicked();

    void on_btn_eliminar_enfermedad_clicked();

    void on_btn_eliminar_operacion_clicked();

    void on_btn_agregar_alergia_clicked();

    void on_btn_agregar_enfermedad_clicked();

    void on_btn_agregar_operacion_clicked();

private:
    Ui::medico_expediente_clinico *ui;
    QString idMedico,idPaciente,nombre,foto,idExpediente,idAlergia,idOperacion,idEnfermedad;
    QSqlDatabase mDatabase;
    QSqlQueryModel *modeloAlergias;
    QSqlQueryModel *modeloEnfermedades;
    QSqlQueryModel *modeloOperaciones;


};

#endif // MEDICO_EXPEDIENTE_CLINICO_H
